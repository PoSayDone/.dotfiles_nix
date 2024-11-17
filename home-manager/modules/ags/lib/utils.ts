import { type Subscribable } from "astal/binding";
import { Gtk, App } from "astal/gtk3";
import { GLib, monitorFile, writeFile, exec, Gio, execAsync } from "astal";
import { transparentScrimWindowNames, scrimWindowNames } from "./variables";
import AstalNotifd from "gi://AstalNotifd?version=0.1";
import { currentPage } from "../widget/ControlCenter";

export type Ref<T> = { ref?: T };

export function range(length: number, start = 1) {
	return Array.from({ length }, (_, i) => i + start);
}

export const activePopupWindows = (scrimType: "transparent" | "opaque") => {
	return App.get_windows().filter((window) => {
		if (scrimType === "transparent") {
			return (
				transparentScrimWindowNames.get().includes(window.name) &&
				window.visible
			);
		} else {
			return (
				scrimWindowNames.get().includes(window.name) && window.visible
			);
		}
	});
};

export function toggleWindow(windowName: string) {
	const w = App.get_window(windowName);

	if (w) {
		if (w.visible) {
			w.visible = false;
			if (windowName == "control-center") currentPage.set("main");
		} else {
			if (transparentScrimWindowNames.get().includes(windowName)) {
				if (windowName == "notifications") {
					const notifications =
						AstalNotifd.get_default().get_notifications();
					if (notifications.length == 0) return;
				}
				App.get_window("transparent-scrim")?.set_visible(true);
			} else {
				activePopupWindows("opaque").forEach((window) => {
					window.visible = false;
				});
				App.get_window("scrim")?.set_visible(true);
			}
			w.visible = true;
		}
	}
}

export function hexToRgb(hex: string) {
	var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
	if (result != null) {
		return {
			r: parseInt(result[1], 16),
			g: parseInt(result[2], 16),
			b: parseInt(result[3], 16),
		};
	}
}

export function lookUpIcon(name?: string, size = 16) {
	if (!name) return null;

	return Gtk.IconTheme.get_default().lookup_icon(
		name,
		size,
		Gtk.IconLookupFlags.USE_BUILTIN,
	);
}

export function monitorColorsChange() {
	monitorFile(`${GLib.getenv("HOME")}/.config/ags/style/colors.scss`, () => {
		const target = "/tmp/astal/style.css";
		exec(
			`sass ${GLib.getenv("HOME")}/.config/ags/style/main.scss ${target}`,
		);
		App.apply_css(target);
	});
}

export function dependencies(packages: string[]) {
	for (const pkg of packages) {
		const result = GLib.find_program_in_path(pkg);
		if (!result) {
			return false;
		}
	}
	return true;
}

export function ensureDirectory(path: string) {
	if (!GLib.file_test(path, GLib.FileTest.EXISTS))
		Gio.File.new_for_path(path).make_directory_with_parents(null);
}

export async function sh(cmd: string | string[]) {
	return execAsync(cmd).catch((err) => {
		console.error(typeof cmd === "string" ? cmd : cmd.join(" "), err);
		return "";
	});
}

export async function bash(
	strings: TemplateStringsArray | string,
	...values: unknown[]
) {
	const cmd =
		typeof strings === "string"
			? strings
			: strings.flatMap((str, i) => str + `${values[i] ?? ""}`).join("");

	return execAsync(["bash", "-c", cmd]).catch((err) => {
		console.error(cmd, err);
		return "";
	});
}

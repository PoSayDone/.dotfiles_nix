import { Gtk } from "astal";
import BarButton from "../BarButton";
import AstalHyprland from "gi://AstalHyprland?version=0.1";

function getLayout(layoutName: string) {
	if (layoutName.includes("English")) {
		return "en";
	} else if (layoutName.includes("Russian")) {
		return "ru";
	} else {
		return "?";
	}
}

export default () => {
	const hyprland = AstalHyprland.get_default();

	return (
		<BarButton className="bar__keyboard-layout">
			<stack
				transitionType={Gtk.StackTransitionType.SLIDE_UP_DOWN}
				halign={Gtk.Align.CENTER}
				hexpand
				setup={(self) =>
					self.hook(
						hyprland,
						"keyboard-layout",
						(_, kbName, layoutName) => {
							if (!kbName) {
								return;
							}
							self.shown = getLayout(layoutName);
						},
					)
				}
			>
				<label name={"en"} label="en" />
				<label name={"ru"} label="ru" />
				<label name={"?"} label="?" />
			</stack>
		</BarButton>
	);
};
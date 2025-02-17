import Tray from "gi://AstalTray";
import BarItem from "../BarItem";
import { bind, timeout } from "astal";
import { App, Gtk, Gdk } from "astal/gtk3";

type BarTrayItemProps = {
	item: Tray.TrayItem;
};

const BarTrayItem = ({ item }: BarTrayItemProps) => {
	return (
		<menubutton
			className="bar__tray-item"
			usePopover={false}
			tooltipMarkup={bind(item, "tooltipMarkup")}
			actionGroup={bind(item, "actionGroup").as((ag) => ["dbusmenu", ag])}
			menuModel={bind(item, "menuModel")}
		>
			<icon gIcon={bind(item, "gicon")} />
		</menubutton>
	);
};

export default () => {
	const tray = Tray.get_default();

	return (
		<revealer
			visible={tray.get_items().length > 0}
			revealChild={tray.get_items().length > 0}
			transitionDuration={300}
			transitionType={Gtk.RevealerTransitionType.SLIDE_LEFT}
			setup={(self) => {
				self.hook(tray, "notify::items", () => {
					if (tray.get_items().length > 0) {
						self.visible = true;
						self.reveal_child = true;
					} else {
						self.reveal_child = false;
						setTimeout(() => {
							self.visible = false;
						}, 300);
					}
				});
			}}
		>
			<BarItem className="bar__tray">
				<box spacing={4} hexpand={false} valign={Gtk.Align.CENTER}>
					{bind(tray, "items").as((items) =>
						items.map((item) => <BarTrayItem item={item} />),
					)}
					{/* {bind(tray, "items").as((items) =>
						items.map((item) => {
							if (item.iconThemePath)
								App.add_icons(item.iconThemePath);
							return <BarTrayItem item={item} />;
						}),
					)} */}
				</box>
			</BarItem>
		</revealer>
	);
};

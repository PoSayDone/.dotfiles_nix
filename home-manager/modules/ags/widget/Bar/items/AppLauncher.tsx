import { App, Gtk } from "astal";
import BarButton from "../BarButton";
import { toggleWindow } from "../../../lib/utils";

export default () => (
	<BarButton
		className="bar__app-launcher"
		onClicked={() => {
			toggleWindow("app-launcher");
		}}
	>
		<box
			className="bar__app-launcher_icon"
			valign={Gtk.Align.CENTER}
			halign={Gtk.Align.CENTER}
			hexpand={true}
			vexpand={true}
		/>
	</BarButton>
);

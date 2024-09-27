import { App, Astal, Widget } from "astal";
import { transparentScrimWindowNames } from "../../lib/variables";
import { activePopupWindows } from "../../lib/utils";

export default () => (
	<window
		visible={false}
		name="transparent-scrim"
		namespace="transparent-scrim"
		layer={Astal.Layer.OVERLAY}
		exclusivity={Astal.Exclusivity.IGNORE}
		anchor={
			Astal.WindowAnchor.TOP |
			Astal.WindowAnchor.LEFT |
			Astal.WindowAnchor.RIGHT |
			Astal.WindowAnchor.BOTTOM
		}
		keymode={Astal.Keymode.NONE}
		application={App}
		className="transparent-scrim"
		setup={(self) => {
			self.hook(self, "notify::visible", () => {
				if (!self.visible) {
					const visiblePopups = activePopupWindows("transparent");
					visiblePopups.forEach((popup) => {
						popup.visible = false;
					});
				}
			});
		}}
	>
		<eventbox
			vexpand={true}
			hexpand={true}
			onClick={(self) => {
				self.parent.visible = false;
			}}
		/>
	</window>
);
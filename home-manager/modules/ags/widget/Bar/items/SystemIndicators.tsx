import Wp from "gi://AstalWp";
import Network from "gi://AstalNetwork";
import Bluetooth from "gi://AstalBluetooth";
import BarButton from "../BarButton";
import { App, bind, Variable } from "astal";
import icons from "../../../lib/icons";
import AstalNotifd from "gi://AstalNotifd?version=0.1";
import { toggleWindow } from "../../../lib/utils";

const BluetoothIndicator = () => {
	const bluetooth = Bluetooth.get_default();
	return (
		<icon
			visible={bind(bluetooth, "isPowered").as((isPowered) => isPowered)}
			icon={bind(bluetooth, "isPowered").as((isPowered) =>
				isPowered ? icons.bluetooth.enabled : icons.bluetooth.disabled,
			)}
		/>
	);
};

const DNDIndicator = () => {
	const notifd = AstalNotifd.get_default();
	return (
		<icon
			visible={bind(notifd, "dontDisturb").as((dnd) => dnd)}
			icon={bind(notifd, "dontDisturb").as(
				(dnd) => icons.notifications[dnd ? "silent" : "noisy"],
			)}
		/>
	);
};

const MicMuteIndicator = () => {
	const mic = Wp.get_default()?.audio.defaultMicrophone!;
	return (
		<icon
			visible={bind(mic, "mute").as((muted) => muted)}
			icon={bind(mic, "mute").as(
				(muted) => icons.audio.mic[muted ? "muted" : "high"],
			)}
		/>
	);
};

const NetworkIndicator = () => {
	const { wifi, wired } = Network.get_default();
	const network = Network.get_default();

	const primary = bind(network, "primary");
	const wifiIcon = bind(wifi, "iconName");
	const wiredIcon = bind(wired, "iconName");

	// TODO: This is a hack to make sure the icon is updated when the primary network changes
	const icon = Variable.derive([primary, wifiIcon], (primary, iconWifi) => {
		if (primary == Network.Primary.WIFI) {
			return iconWifi;
		} else {
			return icons.network.wired;
		}
	});

	return (
		<icon tooltipText={bind(wifi, "ssid").as(String)} icon={bind(icon)} />
	);
};

const AudioIndicator = () => {
	const speaker = Wp.get_default()?.audio.defaultSpeaker!;

	return (
		<icon
			tooltipText={bind(speaker, "volume").as(
				(v) => Math.round(v * 100).toString() + "%",
			)}
			icon={bind(speaker, "volumeIcon")}
		/>
	);
};

export default () => {
	return (
		<BarButton
			clickable={true}
			className="bar__system-indicators"
			onClicked={() => toggleWindow("control-center")}
		>
			<box spacing={10}>
				<AudioIndicator />
				<NetworkIndicator />
				<BluetoothIndicator />
				<DNDIndicator />
				<MicMuteIndicator />
			</box>
		</BarButton>
	);
};
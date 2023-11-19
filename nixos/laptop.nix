{ pkgs, ... }:{
	systemd.services.fix-hyprland-stutters = {
		description = "Sets intel gpu min frequency";
		path = [ pkgs.intel-gpu-tools ];
		script = "intel_gpu_frequency --custom min=550";
		wantedBy = [ "graphical.target" ];
	};

	nixpkgs.config.packageOverrides = pkgs: {
		vaapiIntel = pkgs.vaapiIntel.override { enableHybridCodec = true; };
	};

	hardware.opengl = {
		enable = true;
		driSupport = true;
		driSupport32Bit = true;
		extraPackages = with pkgs; [
			intel-media-driver # LIBVA_DRIVER_NAME=iHD
			vaapiIntel         # LIBVA_DRIVER_NAME=i965 (older but works better for Firefox/Chromium)
			vaapiVdpau
			libvdpau-va-gl
			mesa.drivers
		];
	};
}

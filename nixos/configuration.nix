{ lib, inputs, pkgs, username, system, ... }: {

  imports = [
    ./hardware-configuration.nix
    ./locale.nix
    ./zenbook-acpi.nix
	./laptop.nix
    ./hyprland.nix
  ];

  # nix
  documentation.nixos.enable = false; # .desktop
  nixpkgs.config.allowUnfree = true;
  nix = {
    gc = {
        automatic = true;
        dates = "weekly";
        options = "--delete-older-than 1w";
     };
    settings = {
		experimental-features = "nix-command flakes";
		auto-optimise-store = true;
		substituters = ["https://hyprland.cachix.org"];
		trusted-public-keys = ["hyprland.cachix.org-1:a7pgxzMz7+chwVL3/pzj6jIBMioiJM7ypFP8PwtkuGc="];
    };
  };

  # Lid Close
  services.logind.lidSwitch = "suspend";

  # virtualisation
  virtualisation = {
    podman.enable = true;
    libvirtd.enable = true;
  };

  # dconf
  programs.dconf.enable = true;
  programs.zsh.enable = true;

  # packages
  environment.systemPackages = with pkgs; [
    inputs.matugen.packages.${system}.default
    home-manager
    neovim
    git
    wget
    gcc
	intel-gpu-tools
	chromium
	glxinfo
	libGL
  ];
  environment.sessionVariables.NIXOS_OZONE_WL = "1";
  environment.binsh = "${pkgs.zsh}/bin/zsh";


  fonts.packages = with pkgs; [
    (nerdfonts.override { fonts = [ "JetBrainsMono" ]; })
  ];

  programs.neovim.enable = true;
  programs.neovim.defaultEditor = true;

	#power management
  powerManagement.enable = false;
  services.thermald.enable = true;
  programs.auto-cpufreq.enable = true;
  programs.auto-cpufreq.settings = {
    charger = {
      governor = "performance";
      turbo = "auto";
    };
    battery = {
      governor = "default";
      turbo = "auto";
    };
  };

  # services
  services = {
    xserver = {
      enable = true;
      excludePackages = [ pkgs.xterm ];
      displayManager = {
        lightdm = { 
          enable = true;
          greeter.enable = true;
        };
      };
    };
    printing.enable = true;
    flatpak.enable = true;
  };

  # logind
  services.logind.extraConfig = ''
    HandleLidSwitch=suspend
    HandleLidSwitchExternalPower=ignore
  '';

  # kde connect
  networking.firewall = rec {
    allowedTCPPortRanges = [{ from = 1714; to = 1764; }];
    allowedUDPPortRanges = allowedTCPPortRanges;
  };

  # user
  users.users.${username} = {
    isNormalUser = true;
    shell = pkgs.zsh;
    extraGroups = [
      "networkmanager"
      "wheel"
      "audio"
      "libvirtd"
    ];
  };

  security.rtkit.enable = true;
  security.pam.services.gtklock.text = lib.readFile "${pkgs.gtklock}/etc/pam.d/gtklock";

#audio
  services.pipewire = {
    enable = true;
    alsa.enable = true;
    alsa.support32Bit = true;
    pulse.enable = true;
  };

  # network
  networking = {
    hostName = "posaydone-laptop";
    networkmanager.enable = true;
  };

  # bluetooth
  hardware.bluetooth = {
    enable = true;
    powerOnBoot = false;
    settings.General.Experimental = true; # for gnome-bluetooth percentage
  };

  # bootloader
  boot = {
    tmp.cleanOnBoot = true;
    kernelPackages = pkgs.linuxPackages_zen;
	kernelParams = [ "intel_pstate=active" ];
    loader = {
      timeout = 2;
      systemd-boot.enable = true;
      systemd-boot.configurationLimit = 10;
      efi.canTouchEfiVariables = true;
    };
  };

  system.stateVersion = "23.05";
}

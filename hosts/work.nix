{
  config,
  lib,
  pkgs,
  ...
}: {
  imports = [
    ./shared.nix
    ./modules/hyprland.nix
    ./hardware/work.nix
  ];

  services.xserver.videoDrivers = ["nvidia"];

  hardware = {
    graphics = {
      enable = true;
    };

    nvidia = {
      modesetting.enable = true;
      powerManagement.enable = false;
      powerManagement.finegrained = false;
      open = false;
      nvidiaSettings = true;
      package = config.boot.kernelPackages.nvidiaPackages.stable;
    };

    keyboard.qmk.enable = true;
  };

  environment.systemPackages = with pkgs; [
    via
  ];
  services.udev.packages = [pkgs.via];
}

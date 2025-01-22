{
  inputs,
  pkgs,
  ...
}: {
  xdg = {
    autostart.enable = true;
    portal = {
      enable = true;
      wlr.enable = true;
      extraPortals = [pkgs.xdg-desktop-portal-gtk];
    };
  };

  programs = {
    steam.enable = true;
    hyprland = {
      enable = true;
      package = inputs.hyprland.packages.${pkgs.system}.hyprland;
      portalPackage = inputs.hyprland.packages.${pkgs.system}.xdg-desktop-portal-hyprland;
    };
    hyprlock = {
      enable = true;
      package = inputs.hyprlock.packages.${pkgs.system}.hyprlock;
    };
  };

  security = {
    polkit = {
      enable = true;
      extraConfig = ''
        polkit.addRule(function(action, subject) {
            if (action.id == "org.freedesktop.policykit.exec" &&
                action.lookup("command_line") == "/run/current-system/sw/bin/bash /home/posaydone/.config/nekoray/config/vpn-run-root.sh" &&
                subject.isInGroup("wheel")) {
                return polkit.Result.YES;
            }
        });
        polkit.addRule(function(action, subject) {
            if (action.id == "org.freedesktop.policykit.exec" &&
                RegExp('/run/current-system/sw/bin/pkill -2 -P .*').test(action.lookup("command_line")) &&
                subject.isInGroup("wheel")) {
                return polkit.Result.YES;
            }
        });
      '';
    };
    sudo = {
      enable = true;
      extraRules = [
        {
          groups = ["wheel"];
          commands = [
            {
              command = "/run/current-system/sw/bin/ec_probe";
              options = ["NOPASSWD"];
            }
            {
              command = "${pkgs.nekoray}/bin/nekoray";
              options = ["NOPASSWD"];
            }
          ];
        }
      ];
    };
  };

  environment = {
    systemPackages = with pkgs; [
      adwaita-icon-theme
      nautilus
      gnome-calendar
      gnome-boxes
      gnome-system-monitor
      gnome-control-center
      gnome-weather
      gnome-calculator
      gnome-software # for flatpak
      gnome-disk-utility
    ];
  };

  services = {
    gvfs.enable = true;
    devmon.enable = true;
    udisks2.enable = true;
    upower.enable = true;
    accounts-daemon.enable = true;
    gnome = {
      evolution-data-server.enable = true;
      glib-networking.enable = true;
      gnome-keyring.enable = true;
      gnome-online-accounts.enable = true;
    };
  };
}

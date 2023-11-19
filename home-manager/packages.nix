{ pkgs, ... }:
{
  home.packages = with pkgs; with nodePackages_latest; with gnome; [
    #gui
    telegram-desktop
    kitty
    yazi
    gtklock
    btop
    mpv
	obsidian

    #hyprland
    wl-gammactl
    wl-clipboard
    wf-recorder
    hyprpicker
    grim
    swappy
    slurp
    imagemagick
    pavucontrol
    brightnessctl
    swww
	grimblast

    # tools
    bat
    eza
    ranger
    fd
    ripgrep
    fzf
    socat
    jq
    acpi
    inotify-tools
    ffmpeg
    libnotify
    killall
    zip
    unzip
    glib
	gh

    # langs
    nodejs
    go
    bun
    sassc
    typescript
    meson
    ninja
    eslint
  ];
}

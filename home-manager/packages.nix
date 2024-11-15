{
  inputs,
  pkgs,
  ...
}: {
  home.packages = with pkgs;
  with nodePackages_latest;
  with gnome; [
    #cli
    xclip
    btop
    fd
    ripgrep
    fzf
    inotify-tools
    ffmpeg
    libnotify
    killall
    p7zip
    gh
    tesseract

    #tools
    rustdesk-flutter
    ripdrag
    nekoray
    wineWowPackages.waylandFull
    winetricks
    pamixer
    blueman

    #gui
    lutris
    obs-studio
    wpsoffice
    figma-linux
    zoom-us
    kitty
    foot
    yazi
    mpv
    vesktop
    gimp
    zathura
    mission-center
    loupe
    simple-scan
    fragments
    transmission_4-gtk
    ghex
    (pkgs.callPackage ../pkgs/hiddify/derivation.nix {})
    telegram-desktop
    cassette

    #hypr
    inputs.hyprsettings.packages.${pkgs.system}.default
    socat # for monitor connect script
    hyprpicker
    hypridle
    wl-gammactl
    wl-clipboard
    wf-recorder
    grimblast
    pavucontrol
    brightnessctl
    swww
    gsettings-desktop-schemas
    material-icons
    corefonts
    grim
    slurp

    # games
    (prismlauncher.override {jdks = [jdk8 jdk17 jdk21];})

    bruno
    zed-editor
    gnome-builder
    flatpak-builder
    docker-compose
    android-studio

    #development
    # inputs.dbvisualizer-nur.packages.${pkgs.system}.dbvisualizer
    dbeaver-bin
    jetbrains.rider
    bruno
    zed-editor
    gnome-builder
    flatpak-builder
    docker-compose
    android-studio

    # langs
    black
    nodejs
    bun
    sassc
    meson
    yarn
  ];
}

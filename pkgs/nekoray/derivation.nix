{
  stdenv,
  fetchzip,
  makeWrapper,
  makeDesktopItem,
  autoPatchelfHook,
  copyDesktopItems,
  qtbase,
  qtsvg,
  qttools,
  qtx11extras,
  qtwayland,
}:
stdenv.mkDerivation rec {
  pname = "nekoray";
  version = "3.26";
  date = "2023-12-09";

  src = fetchzip {
    url = "https://github.com/MatsuriDayo/nekoray/releases/download/${version}/nekoray-${version}-${date}-linux64.zip";
    hash = "sha256-Wp97qT3VBlSxK2qAVLxm041NR0c5vi8SSI/4VdwvQTY=";
  };

  desktopItems = [
    (makeDesktopItem {
      name = pname;
      desktopName = pname;
      exec = "nekoray";
      icon = "nekoray";
      comment = "Qt based cross-platform GUI proxy configuration manager";
      categories = ["Network" "Utility"];
    })
  ];

  dontWrapQtApps = true;

  nativeBuildInputs = [autoPatchelfHook makeWrapper copyDesktopItems qtwayland];
  buildInputs = [
    qtwayland
    qtbase
    qtsvg
    qttools
    qtx11extras
  ];

  installPhase = ''
    runHook preInstall

    mkdir -p $out/{share/icons/hicolor/128x128/apps,usr/lib/nekoray}
    install -Dm755 ./{nekobox_core,nekoray_core,nekoray} $out/usr/lib/nekoray/
    install -Dm644 ./{geosite.db,geosite.dat,geoip.db,geoip.dat} $out/usr/lib/nekoray/
    install -Dm644 ./nekoray.png $out/share/icons/hicolor/128x128/apps/

    makeWrapper $out/usr/lib/nekoray/nekoray $out/bin/nekoray \
      --add-flags "-- -appdata"

    runHook postInstall
  '';
}

{
  stdenv,
  lib,
  fetchurl,
  qtbase,
  qmake,
  wrapQtAppsHook,
}:
stdenv.mkDerivation rec {
  pname = "scanoval";
  version = "1.7.0";

  src = fetchurl {
    url = "https://drop5.dmf.link/dl/UOq0d";
    sha256 = "sha256-mLw5jRLXUM8zYFBRIrjbl10xs4LSd5RNdl7pV/ELHeg=";
  };

  buildInputs = [qtbase qmake];
  nativeBuildInputs = [wrapQtAppsHook];

  unpackPhase = ''
    ar x $src
    tar xf data.tar.xz
  '';

  meta = with lib; {
    description = "An example package from a .deb file";
    license = "unknown";
    platforms = platforms.linux;
  };
}

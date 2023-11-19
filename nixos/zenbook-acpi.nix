{ pkgs, config, lib, ... }:
let
  zenbook-acpi = pkgs.stdenv.mkDerivation rec {
    pname = "asus-zenbook-ux3402za-acpi-tables";
    version = "0.0.1";
    src = pkgs.fetchFromGitHub {
      owner = "thor2002ro";
      repo = "asus_zenbook_ux3402za";
      rev = "54cc1488e8dd2ffbf3dbffd390e42d9a4657a2de";
      sha256 = "sha256-o32kAz8z/AMsKfCmU0nHxhcerDudYqJduHhRCeZbVPQ=";
    };

    nativeBuildInputs = with pkgs; [
      acpica-tools
      cpio
    ];

    buildPhase = ''
      mkdir acpi 
      mv Sound/ssdt-csc3551.dsl acpi/ssdt.dsl
      iasl -sa acpi/ssdt.dsl
    '';

    installPhase = '' 
      mkdir -p $out/boot
      mkdir -p kernel/firmware/acpi
      cp acpi/ssdt.aml kernel/firmware/acpi/
      find kernel | cpio -H newc --create > patched_acpi_tables.cpio
      cp patched_acpi_tables.cpio $out/boot/tables.cpio
    '';
  };
in
{
  boot.loader.systemd-boot = {
    extraFiles."tables.cpio" = "${zenbook-acpi}/boot/tables.cpio";
  };
  boot.initrd.prepend = [ "${/boot/tables.cpio}" ];
}

{ pkgs, inputs, ... }:
let
  moreWaita = pkgs.stdenv.mkDerivation {
    name = "MoreWaita";
    src = inputs.more-waita;
    installPhase = ''
        mkdir -p $out/share/icons
        mv * $out/share/icons
    '';
  };
in
{
	home = {
		packages = with pkgs; [
			adw-gtk3
			moreWaita
		];
		file = {
		  ".local/share/icons/MoreWaita" = {
			source = "${moreWaita}/share/icons";
		  };
		};
	};
	gtk = {
		enable = true;
		theme = {
			package = pkgs.adw-gtk3;
			name = "adw-gtk3-dark";
		};
		iconTheme = {
			package = pkgs.gnome.adwaita-icon-theme;
			name = "MoreWaita";
		};
		font = {
			name = "Google Sans";
			size = 12;
		};
	};
	qt = {
		enable = true;
		platformTheme = "gtk";
		style.name = "adwaita-dark";
	};
}

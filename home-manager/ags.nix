{ inputs, pkgs, ... }:
{
  imports = [ inputs.ags.homeManagerModules.default ];

  home.packages = with pkgs; [
    (python311.withPackages (p: [ p.python-pam p.requests p.material-color-utilities ]))
  ];

  programs.ags = {
    enable = true;
    extraPackages = [ pkgs.libsoup_3 ];
  };
}

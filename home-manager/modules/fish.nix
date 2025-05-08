{...}: {
  programs = {
    direnv = {
      enable = true;
      enableBashIntegration = true; # see note on other shells below
      nix-direnv.enable = true;
    };

    fish = {
      enable = true;
      generateCompletions = true;
      interactiveShellInit = ''
        fish_vi_key_bindings
      '';
      shellAliases = {
        vim = "nvim";
        ls = "ls --color";
        ctrl-l = "clear";
        C-l = "ctrl-l";
        control-l = "clear";
        clean = "clear";
        rw = "sudo nixos-rebuild switch --flake $HOME/.nixdots#posaydone-work";
        rl = "sudo nixos-rebuild switch --flake $HOME/.nixdots#posaydone-laptop";
      };
    };

    starship = {
      enable = true;
      enableFishIntegration = true;
    };
  };
}

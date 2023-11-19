{ pkgs, ... }:{
    home.packages = with pkgs; [
      thefuck
    ];

    programs.zsh = {
      enable = true;
      oh-my-zsh = {
        theme = "awesomepanda";
        enable = true;
        plugins = [
          "fzf" # fuzzy auto-completion and key bindings https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/fzf
          "python" # https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/python
          "systemd" # useful aliases for systemd. https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/systemd
          "thefuck" # corrects your previous console command. https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/thefuck
          "tmux" # https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/tmux
          "z" # https://github.com/ohmyzsh/ohmyzsh/tree/master/plugins/z
        ];
      };

      history = {
        share = true; # false -> every terminal has it's own history
        size = 9999999; # Number of history lines to keep.
        save = 9999999; # Number of history lines to save.
        ignoreDups = true; # Do not enter command lines into the history list if they are duplicates of the previous event.
        extended = true; # Save timestamp into the history file.
      };

      dirHashes = {
      };

      shellAliases = {
        "dl" = "ls -lhtr --color=always ~/Downloads | tail -n 10"; # Show the 10 newest Downloads
        "o" = "less";
        "gg" = "git grep";
        "m" = "mpv";
        "s" = "tmux a"; # reminiscence to good old GNU screen ;-)
        "open" = "xdg-open";
		"rb" = "sudo nixos-rebuild switch --flake .#posaydone-laptop";
		"rh" = "home-manager switch --flake .#posaydone";
      };
    };
}

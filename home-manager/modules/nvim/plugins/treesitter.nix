{config, ...}: {
  programs.nixvim.plugins = {
    treesitter = {
      enable = true;

      nixvimInjections = true;

      folding = true;
      indent = true;

      grammarPackages = with config.programs.nixvim.plugins.treesitter.package.builtGrammars; [
        prisma
        svelte
        bash
        c
        c_sharp
        css
        scss
        html
        javascript
        lua
        nix
        norg
        python
        rust
        vimdoc
      ];
    };

    treesitter-refactor = {
      enable = true;
      highlightDefinitions.enable = true;
    };
  };
}
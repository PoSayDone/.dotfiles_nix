{
  description = "NixOS configuration";

  outputs = inputs @ {
    nixpkgs,
    home-manager,
    ...
  }: let
    username = "posaydone";
    system = "x86_64-linux";
  in {
    nixosConfigurations = {
      "posaydone-work" = nixpkgs.lib.nixosSystem {
        inherit system;
        specialArgs = {
          inherit inputs username system;
        };
        modules = [
          ./hosts/work.nix
          {
            nix.settings.trusted-users = ["posaydone"];
          }
          home-manager.nixosModules.home-manager
          {
            home-manager.backupFileExtension = "old";
            home-manager = {
              useGlobalPkgs = true;
              useUserPackages = true;
              users.posaydone = import ./home-manager/home.nix;
              extraSpecialArgs = {inherit inputs username system;};
            };
          }
        ];
      };

      "posaydone-laptop" = nixpkgs.lib.nixosSystem {
        inherit system;
        specialArgs = {inherit inputs username system;};
        modules = [
          {
            nix.settings.trusted-users = ["posaydone"];
          }
          ./hosts/laptop.nix
          home-manager.nixosModules.home-manager
          {
            home-manager.backupFileExtension = "old";
            home-manager = {
              useGlobalPkgs = true;
              useUserPackages = true;
              users.posaydone = import ./home-manager/home.nix;
              extraSpecialArgs = {inherit inputs username system;};
            };
          }
        ];
      };
    };
  };

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    home-manager = {
      url = "github:nix-community/home-manager";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    nbfc-linux = {
      url = "github:nbfc-linux/nbfc-linux";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    hyprland = {
      url = "git+https://github.com/hyprwm/Hyprland?submodules=1";
    };
    hyprlock = {
      url = "github:hyprwm/hyprlock";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    hypridle = {
      url = "github:hyprwm/hypridle";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    astal = {
      url = "github:Aylur/astal";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    ags = {
      url = "github:Aylur/ags";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.astal.follows = "astal";
    };
    matugen.url = "github:InioX/Matugen?rev=0bd628f263b1d97f238849315f2ce3ab4439784e";
    nixvim = {
      url = "github:nix-community/nixvim";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    transparent-nvim = {
      url = "github:xiyaowong/transparent.nvim";
      flake = false;
    };
    hyprsettings = {
      url = "github:PoSayDone/hyprsettings";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    dbvisualizer-nur = {
      url = "github:jeremiehuchet/nur-packages";
    };
    figma-linux = {
      url = "github:HelloWorld017/figma-linux-nixos";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
}


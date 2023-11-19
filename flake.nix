{
  description = "NixOS configuration";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    home-manager.url = "github:nix-community/home-manager";
    home-manager.inputs.nixpkgs.follows = "nixpkgs";
    hyprland.url = "github:hyprwm/Hyprland";
    ags.url = "github:Aylur/ags";
    matugen.url = "github:InioX/Matugen";
    auto-cpufreq = {
		url = "github:adnanhodzic/auto-cpufreq";
		inputs.nixpkgs.follows = "nixpkgs";
    };
    more-waita = {
		url = "https://github.com/somepaulo/MoreWaita/archive/refs/heads/main.zip";
		flake = false;
    };
  };


  outputs = { home-manager, matugen, nixpkgs, ... }@inputs:
  let
    username = "posaydone";
    system = "x86_64-linux";
  in
  {
    nixosConfigurations."posaydone-laptop" = nixpkgs.lib.nixosSystem {
      specialArgs = { inherit inputs username system; };
      modules = [ 
        ./nixos/configuration.nix
        inputs.auto-cpufreq.nixosModules.default
      ];
    };

    homeConfigurations."${username}" = home-manager.lib.homeManagerConfiguration {
      pkgs = import nixpkgs {
        inherit system;
        config.allowUnfree = true;
      };
      extraSpecialArgs = { inherit inputs username system; };
      modules = [ ./home-manager/home.nix ];
    };
  };
}

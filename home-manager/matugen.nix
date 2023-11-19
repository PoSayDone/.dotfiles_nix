{ inputs, ...}: {
  imports = [
    inputs.matugen.nixosModules.default
  ];

 programs.matugen = {
    enable = true;
  };
}

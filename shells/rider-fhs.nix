{pkgs ? import <nixpkgs> {}}:
(pkgs.buildFHSEnv {
  name = "rider-env";
  targetPkgs = pkgs: (with pkgs; [
    dotnetCorePackages.dotnet_9.sdk
    dotnetCorePackages.dotnet_9.aspnetcore
    powershell
  ]);
  multiPkgs = pkgs: (with pkgs; [
    ]);
  runScript = "nohup rider &";
})
.env

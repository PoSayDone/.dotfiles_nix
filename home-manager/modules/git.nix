{
  programs.git = {
    enable = true;
    signing.format = "ssh";
    userName = "Arseniy Knyazev";
    userEmail = "poseaydone@ya.ru";
  };
  programs.gh = {
    enable = true;
    gitCredentialHelper.enable = true;
  };
}

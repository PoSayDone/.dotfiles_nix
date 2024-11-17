{
  programs.nixvim.plugins.lualine = {
    enable = true;

    # +-------------------------------------------------+
    # | A | B | C                             X | Y | Z |
    # +-------------------------------------------------+
    settings = {
      options = {
        theme = "one";
        globalstatus = true;
        sectionSeparators = {
          left = "";
          right = "";
        };
        componentSeparators = {
          left = "";
          right = "";
        };
      };

      sections = {
        lualine_a = ["mode"];
        lualine_b = ["filename" "branch" "diff"];
        lualine_c = ["fileformat"];

        lualine_x = [
          "diagnostics"
          # Show active language server
          {
            name.__raw = ''
              function()
              local msg = ""
              local buf_ft = vim.api.nvim_buf_get_option(0, 'filetype')
              local clients = vim.lsp.get_active_clients()
              if next(clients) == nil then
                return msg
                  end
                  for _, client in ipairs(clients) do
                    local filetypes = client.config.filetypes
                      if filetypes and vim.fn.index(filetypes, buf_ft) ~= -1 then
                        return client.name
                          end
                          end
                          return msg
                          end
            '';
            icon = "";
            color.fg = "#ffffff";
          }
        ];
        lualine_y = ["progress" "filetype"];
        lualine_z = ["location"];
      };
    };
  };
}

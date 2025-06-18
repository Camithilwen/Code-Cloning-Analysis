{
  description = "A Nix-flake-based Python development environment";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-25.05";

  outputs = inputs:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forEachSupportedSystem = f: inputs.nixpkgs.lib.genAttrs supportedSystems (system: f {
        pkgs = import inputs.nixpkgs {
          inherit system;
          config.allowUnfree = true;
          overlays = [ inputs.self.overlays.default ];
        };
      });

      /*
       * Change this value ({major}.{min}) to
       * update the Python virtual-environment
       * version. When you do this, make sure
       * to delete the `.venv` directory to
       * have the hook rebuild it for the new
       * version, since it won't overwrite an
       * existing one. After this, reload the
       * development shell to rebuild it.
       * You'll see a warning asking you to
       * do this when version mismatches are
       * present. For safety, removal should
       * be a manual step, even if trivial.
       */
      version = "3.13";
    in
    {
      overlays.default = final: prev: rec {
        nodejs = prev.nodejs;
        yarn = (prev.yarn.override { inherit nodejs;  });
      };
      devShells = forEachSupportedSystem ({ pkgs }:
        let
          concatMajorMinor = v:
            pkgs.lib.pipe v [
              pkgs.lib.versions.splitVersion
              (pkgs.lib.sublist 0 2)
              pkgs.lib.concatStrings
            ];

          python = pkgs."python${concatMajorMinor version}";
        in
        {
          default = pkgs.mkShell {
            venvDir = ".venv";


            postShellHook = ''
             venvVersionWarn() {
              	local venvVersion
              	venvVersion="$("$venvDir/bin/python" -c 'import platform; print(platform.python_version())')"

              	[[ "$venvVersion" == "${python.version}" ]] && return

              	cat <<EOF
              Warning: Python version mismatch: [$venvVersion (venv)] != [${python.version}]
                       Delete '$venvDir' and reload to rebuild for version ${python.version}
              EOF
              }

              venvVersionWarn
            '';

            packages = with python.pkgs; [
              pkgs.python312
              pkgs.uv
              pkgs.lmstudio
              pkgs.node2nix
              pkgs.nodejs
              pkgs.nodePackages.pnpm
              pkgs.yarn
              pkgs.grpc
              venvShellHook
              pip
              jupyter
              jupytext
              pymilvus
              kaggle

              /* Add whatever else you'd like here. */
              # pkgs.basedpyright

              # pkgs.black
              /* or */
              # python.pkgs.black

              # pkgs.ruff
              /* or */
              # python.pkgs.ruff
            ];

            env = {
              NIXPKGS_ALLOW_UNFREE=1;
              };

          #  shellHook = ''
          #  # Create a virtual environment if it doesn't exist
          #  if [ ! -d ".venv" ]; then
          #    uv venv .venv
          #  fi
          #  source .venv/bin/activate
          #  echo "uv pip env ready"
          #  export UV_PYTHON_PREFERENCE="only-system";
          #  export UV_PYTHON=${python}
          #  '';
          };
        });
    };
}

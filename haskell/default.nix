# let
#   pkgs = import <nixpkgs> {};
#   # haskellPackages = pkgs.haskell.packages.ghc92;
#   haskellPackages = pkgs.haskellPackages;
# in
#   haskellPackages.shellFor {
#     packages = p: [
#     ];
#     buildInputs = [
#       pkgs.zlib
#       haskellPackages.haskell-language-server
#       (pkgs.symlinkJoin {
#         inherit (pkgs.stack) name pname version;
#         paths = [pkgs.stack];
#         nativeBuildInputs = [pkgs.makeWrapper];
#         postBuild = ''
#           wrapProgram "$out/bin/stack" \
#             --add-flags "--no-nix" \
#             --add-flags "--system-ghc" \
#             --add-flags "--no-install-ghc"
#         '';
#       })
#     ];
#   }
let
  pkgs = import <nixpkgs> {};
in
  pkgs.mkShell {
    packages = [
      pkgs.zlib
      pkgs.stack
      (pkgs.haskell-language-server.override {supportedGhcVersions = ["927"];})
      pkgs.exercism
    ];
  }

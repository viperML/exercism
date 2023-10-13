with import <nixpkgs> {};
  mkShell.override {
    stdenv = llvmPackages.stdenv;
  } {
    packages = [
      exercism
      clang-tools
      bear
      just
    ];

    shellHook = ''
      just
    '';
  }

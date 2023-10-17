with import <nixpkgs> {};
  mkShell.override {
    # stdenv = llvmPackages.stdenv;
  } {
    packages = [
      exercism
      clang-tools
      bear
      just
      gdb
    ];

    shellHook = ''
      just
    '';

    hardeningDisable = ["all"];
  }

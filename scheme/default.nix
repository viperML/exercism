with import <nixpkgs> {};
mkShell {
  packages = [
    exercism
    guile
  ];
}

with import <nixpkgs> {};
mkShellNoCC {
  packages = [
    exercism
  ];
}

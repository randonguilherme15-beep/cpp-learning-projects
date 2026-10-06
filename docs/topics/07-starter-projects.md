# Starter Projects

[Repository overview](../../README.md) · [Build guide](../building.md)

Minimal entry points and duplicate scaffolding retained as part of the learning history.

## Console Starter

A minimal C++ entry point preserved from the original project layout.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PizzaPartyMath/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** The substantive pizza-budget exercise is in the nested PizzaPartyMath directory.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PizzaPartyMath/main.cpp" -o "build/console-starter.exe"
```

## Neon Security Academy Snapshot

A duplicate source snapshot of the Neon Security Academy exercise.

**Source:** [original file](../../ProgrammazioneC%2B%2B/Visual%20Studio%20Progect/.newproject/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Retained for history; prefer the parent-directory version for reading and compilation.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/Visual Studio Progect/.newproject/main.cpp" -o "build/neon-security-academy-snapshot.exe"
```

## Nested Console Starter

An additional minimal entry point from the original nested workspace.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PizzaPartyMath/PizzaPartiMath/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Preserved as a separate starter; do not compile all entry points into one executable.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/main.cpp" -o "build/nested-console-starter.exe"
```

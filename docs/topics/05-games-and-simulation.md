# Games and Simulation

[Repository overview](../../README.md) · [Build guide](../building.md)

Menu-driven systems, state transitions, combat rules, and resource management.

## Boss Arena

A console combat exercise built around player choices, conditional actions, and changing combat state.

**Source:** [original file](../../ProgrammazioneC%2B%2B/BossArena/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** A standalone learning prototype with a fixed scenario.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/BossArena/main.cpp" -o "build/boss-arena.exe"
```

## Neon Arena

Organises a console game around Player and Enemy structs and a Game class, with input helpers, randomised encounters, and file streams.

**Source:** [original file](../../ProgrammazioneC%2B%2B/NeonArena/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Gameplay and save-file behaviour should be validated independently of successful compilation.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/NeonArena/main.cpp" -o "build/neon-arena.exe"
```

## Neon Arena Shop

Practises menu navigation and purchase decisions in a game-themed shop.

**Source:** [original file](../../ProgrammazioneC%2B%2B/NegozioNeonArena/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** This is a separate executable, not a module linked into Neon Arena.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/NegozioNeonArena/main.cpp" -o "build/neon-arena-shop.exe"
```

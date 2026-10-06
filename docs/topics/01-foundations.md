# Programming Foundations

[Repository overview](../../README.md) · [Build guide](../building.md)

Console input and output, arithmetic, branches, loops, and small functions.

## Access Decision Exercise

Uses console input and conditional logic to practise a simulated access decision.

**Source:** [original file](../../ProgrammazioneC%2B%2B/Accesso%20al%20server%20centrale/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Educational control flow; it does not implement real access control.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/Accesso al server centrale/main.cpp" -o "build/access-decision-exercise.exe"
```

## City Selection Menu

Maps a numeric selection to one of four Australian city names using a switch statement.

**Source:** [original file](../../ProgrammazioneC%2B%2B/SceltaCitta/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** An introductory branch-selection exercise.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/SceltaCitta/main.cpp" -o "build/city-selection-menu.exe"
```

## Four-Operation Calculator

Implements addition, subtraction, multiplication, and division through a switch statement.

**Source:** [original file](../../ProgrammazioneC%2B%2B/CalcolatriceBase.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Division by zero has an explicit guard; stream extraction errors still need handling.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/CalcolatriceBase.cpp" -o "build/four-operation-calculator.exe"
```

## Pizza Party Budget

Computes slice distribution, remainders, food and drink costs, and the remaining budget for a fixed scenario.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PizzaPartyMath/PizzaPartiMath/PizzaPartyMath/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Uses embedded sample values rather than interactive input.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/PizzaPartyMath/main.cpp" -o "build/pizza-party-budget.exe"
```

## Types and Console Output

Introduces integer, floating-point, character, Boolean, and string values through console output.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PrimoProgramma/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** The printed values are fixed demonstration data.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PrimoProgramma/main.cpp" -o "build/types-and-console-output.exe"
```

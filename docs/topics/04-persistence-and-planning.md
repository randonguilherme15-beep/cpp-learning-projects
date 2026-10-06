# Persistence and Planning

[Repository overview](../../README.md) · [Build guide](../building.md)

File streams, saved state, budget calculations, and structured reports.

## Australia Budget Planner

Separates input helpers, plan configuration, extra-expense tracking, summaries, and text report export. Uses a struct and vector for additional expenses.

**Source:** [original file](../../ProgrammazioneC%2B%2B/AustraliaPlannerPro/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** A budgeting simulation with embedded assumptions. Reports are written to `AustraliaPlanner_Report.txt` in the working directory.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/AustraliaPlannerPro/main.cpp" -o "build/australia-budget-planner.exe"
```

## Australia Planning Exercise

A console exercise that combines user input, calculations, and decisions in an Australia-themed scenario.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PizzaPartyMath/PizzaPartiMath/MissioneAustralia/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** An early standalone exercise, separate from Australia Budget Planner.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/MissioneAustralia/main.cpp" -o "build/australia-planning-exercise.exe"
```

## Travel Budget Calculator

Reads a traveller name, trip duration, daily spending, and budget; calculates expected spending and remaining funds.

**Source:** [original file](../../ProgrammazioneC%2B%2B/PizzaPartyMath/PizzaPartiMath/BudgetViaggio/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** A direct arithmetic model without currency conversion or input recovery.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/BudgetViaggio/main.cpp" -o "build/travel-budget-calculator.exe"
```

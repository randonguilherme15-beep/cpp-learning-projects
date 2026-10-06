# Worked Examples

These scenarios use the current source programs. Expected results below are described in English; console wording remains as implemented. Numerical input is supplied one value per prompt.

## Four-Operation Calculator

Build `ProgrammazioneC++/CalcolatriceBase.cpp`. Enter `8`, `2`, then operation `4`.

Expected result: `Result: 4`. With inputs `8`, `0`, `4`, the program prints its division-by-zero error instead of performing the division.

## Travel Budget Calculator

Build `ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/BudgetViaggio/main.cpp`.

| Prompt meaning | Input |
| --- | --- |
| Name | Alex |
| Trip duration in days | 4 |
| Spending per day | 25 |
| Total budget | 150 |

Expected spending is `100`; the remaining budget is `50`.

## Pizza Party Budget

Build `ProgrammazioneC++/PizzaPartyMath/PizzaPartiMath/PizzaPartyMath/main.cpp` and run without input.

The embedded scenario has seven pizzas, eight slices per pizza, and six people. It yields `56` slices, `9` slices per person, and `2` leftover slices. Food and drinks cost `79.3`, leaving `20.7` from a budget of `100`.

## City Selection Menu

Build `ProgrammazioneC++/SceltaCitta/main.cpp` and enter `3`. The selected city is `Perth`.

## Verification scope

The five scenarios above, including the calculator error case, were executed on Windows on 6 October 2026. These checks cover specific behaviours; they are not an exhaustive test suite.

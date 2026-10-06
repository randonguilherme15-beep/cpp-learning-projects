# Assessment and Practice

[Repository overview](../../README.md) · [Build guide](../building.md)

Question banks, scoring, and interactive revision tools.

## Entrance Exam Practice

Uses a question structure, vectors, timing, and file output for an interactive entrance-exam practice session.

**Source:** [original file](../../ProgrammazioneC%2B%2B/Esame%20preparatorio%20Unipd/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** An independently authored revision aid; question accuracy and scoring are not institutionally certified.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/Esame preparatorio Unipd/main.cpp" -o "build/entrance-exam-practice.exe"
```

## Extended Entrance Exam Practice

An expanded question-based practice program with answer processing, timing, and saved results.

**Source:** [original file](../../ProgrammazioneC%2B%2B/Esame%20preparatorio%20Unipd/risultati_TOLCI_50_domande/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** Stored results are historical practice data. Build success does not validate the educational content.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/Esame preparatorio Unipd/risultati_TOLCI_50_domande/main.cpp" -o "build/extended-entrance-exam-practice.exe"
```

## Neon Security Academy

Combines a simulated access-code challenge, role selection, and a five-question programming exercise.

**Source:** [original file](../../ProgrammazioneC%2B%2B/Visual%20Studio%20Progect/main.cpp)

**Build status:** Compiles with the tested C++17 toolchain.

**Current scope:** The access code is embedded demonstration data, not a security mechanism.

From the repository root, after creating `build/`:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/Visual Studio Progect/main.cpp" -o "build/neon-security-academy.exe"
```

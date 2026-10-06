# Building the Projects

## Requirements

A C++17-capable compiler and a terminal. Validation used GCC on Windows; no third-party C++ libraries were needed for the inspected source programs.

## Windows PowerShell

From the repository root:

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/CalcolatriceBase.cpp" -o build/demo.exe
.\build\demo.exe
```

## Linux or macOS with GCC

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic "ProgrammazioneC++/CalcolatriceBase.cpp" -o build/demo
./build/demo
```

The POSIX recipe is provided for equivalent toolchains; it was not executed on Linux or macOS during this review. Substitute the source from the topic catalogue to build another program.

## Program boundaries

Each catalogue entry is a separate executable. Compiling the entire collection with a wildcard would combine multiple `main` functions and fail at link time. Local headers must stay beside their corresponding source. Code::Blocks project files remain available as historical IDE configurations; command-line compilation was the verified path.

## Runtime files

Programs using relative filenames read and write in the process working directory. Run persistence examples from a disposable directory for repeatable results. The hotel project uses `camere.txt`; Australia Budget Planner exports `AustraliaPlanner_Report.txt`. Generated files and binaries are ignored. Existing tracked historical reports are retained.

## Troubleshooting

- Missing compiler: install or select your C++ toolchain and make `g++` available on `PATH`.
- Multiple entry points: compile one catalogue entry at a time.
- Unreadable accented text: use a terminal configured for UTF-8.
- Failed compilation in a draft: consult [validation](validation.md) before treating the failure as an environment problem.

# C Projects

Small programs I built while learning C, from command-line exercises to a multi-file terminal game. Each folder contains its own source code.

| Project | What it demonstrates | Run |
| --- | --- | --- |
| [Password Strength Checker](Project%201%20-%20Password%20Strength%20Checker/) | String input and simple strength rules | `gcc Main.c -o password-checker` |
| [Tic-Tac-Toe](Project%202%20-%20Tic-Tac-Toe/) | Game state and turn-based logic | `gcc Main.c -o tic-tac-toe` |
| [Contact Book](Project%203%20-%20Contact%20Book/) | Contact records, lookup, and text-file storage | `gcc Main.c -o contact-book` |
| [Snake Game](Project%204%20-%20Snake%20Game/) | Multi-file C program with a Makefile and terminal display | Run `make` inside its folder |

Run each command from the corresponding project directory. On Windows with MSYS2, use `./program-name.exe`; on macOS/Linux, use `./program-name`. The Snake Game uses `unistd.h` and ANSI terminal controls, so it may require a Unix-like environment.

These are learning projects. The contact book's file parser assumes correctly formatted records; I would harden its input validation before using it with untrusted files.

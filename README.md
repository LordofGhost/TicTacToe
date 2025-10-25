# Tic Tac Toe

A simple terminal-based Tic Tac Toe game implemented in C++.

This repository includes a small playable game and an AI opponent that uses a variant of the MiniMax algorithm (Negamax) to play perfectly.

## Features

- Play Tic Tac Toe in the terminal.
- Enemy AI uses a full search (Negamax) to choose optimal moves.
- Small, readable C++ codebase suitable for study and extension.

## Build and run

Requirements
- A C++ compiler supporting C++23 or later.
- CMake (version 3.x or newer).

Build from the command line (recommended):

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

After building, run the executable from the build directory:

```bash
./src/TicTacToe
```

If you use CLion, open this project as a CMake project and run the `TicTacToe` target.

## How to play

The game runs in the terminal and prompts the player for moves. The exact input method is the simple number prompt shown by the program. Follow the on-screen instructions to place X or O; the AI will respond with its move.

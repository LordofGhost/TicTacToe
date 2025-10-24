#ifndef MAIN_H
#define MAIN_H

#include "Board.h"

class TicTacToe {
    bool playerFirst;
    Board board;

public:
    TicTacToe();

    // Main game loop
    void game();

    void printResult() const;

    [[nodiscard]] bool isGameRunning() const;

    void playerMove();
};

#endif //MAIN_H

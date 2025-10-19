#ifndef MAIN_H
#define MAIN_H

#include "Player.h"
#include "Enemy.h"

class TicTacToe {
    bool playerFirst;
    Enemy enemy;
    Player player;

public:
    TicTacToe();

    // Main game loop
    void game();

    void printBoard();

    void printResult();

    bool isGameRunning();
};

#endif //MAIN_H

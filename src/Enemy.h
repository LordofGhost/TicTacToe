#ifndef ENEMY_H
#define ENEMY_H

#include <bitset>

#include "Board.h"

constexpr int EVAL_MATE = 30000;
constexpr int EVAL_INFINITE = 31000;
constexpr int EVAL_NONE = 31100;

class Enemy {
public:
    static void move(Board &board);

private:
    static int negamax(Board &board, const Board::Player &p, const int &depth);
};

#endif //ENEMY_H

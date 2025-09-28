#ifndef ENEMY_H
#define ENEMY_H

#include <bitset>
#include <vector>

class Enemy {
public:
    static std::bitset<9> aiMove(const std::bitset<9> &boardSelf, const std::bitset<9> &boardTarget);

private:
    static std::vector<std::bitset<9> > generateMoves(std::bitset<9> myBoard, std::bitset<9> enemyBoard);

    static int negamax(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth);
};

#endif //ENEMY_H

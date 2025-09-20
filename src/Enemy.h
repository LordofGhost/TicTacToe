#ifndef ENEMY_H
#define ENEMY_H

#include <bitset>
#include <vector>

class Enemy {
    void aiMove(std::bitset<9> &boardSelf, const std::bitset<9> &boardTarget);

public:
    static std::vector<std::bitset<9> > generateMoves(std::bitset<9> myBoard, std::bitset<9> enemyBoard);

    int max(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth);

    int min(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth);
};

#endif //ENEMY_H

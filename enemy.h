
#ifndef ENEMY_H
#define ENEMY_H
#include <bitset>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "logic.h"
#include "main.h"
#include <iostream>

std::vector<std::bitset<9>> generateMoves(std::bitset<9> myBoard, std::bitset<9> enemyBoard);
int max(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth);
int min(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth);
#endif //ENEMY_H





#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <bitset>
#include "logic.h"
#include "enemy.h"

// action functions
void playerMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget);
void aiMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget);

// CLI output functions
void convertBoard(std::bitset<9> & boardAi, std::bitset<9> & boardPlayer, char* boardInChar);
void printBoard3x3(const char* position);

// state checking functions
bool isGameRunning(std::bitset<9> & boardPlayer, std::bitset<9> & boardAi);

#endif //MAIN_H

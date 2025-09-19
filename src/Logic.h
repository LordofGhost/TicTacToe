#ifndef LOGIC_H
#define LOGIC_H

#include <bitset>

class Logic {
public:
    static bool checkForWinningRow(const std::bitset<9> &board);

    static bool checkForDraw(const std::bitset<9> &board1, const std::bitset<9> &board2);
};


#endif //LOGIC_H

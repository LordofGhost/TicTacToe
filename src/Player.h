#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <bitset>


class Player {
    std::bitset<9> board;

public:
    virtual ~Player() = default;

    Player() : board(0) {
    };

    [[nodiscard]] std::bitset<9> &getBoard() {
        return board;
    }

    [[nodiscard]] const std::bitset<9> &getBoard() const {
        return board;
    }

    void virtual move(const Player &enemy);

    static bool checkForWinningRow(const std::bitset<9> &board);

    static bool checkForDraw(const std::bitset<9> &board1, const std::bitset<9> &board2);
};


#endif //TICTACTOE_PLAYER_H

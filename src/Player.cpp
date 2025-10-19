#include "Player.h"

#include <iostream>

void Player::move(const Player &enemy) {
    std::print("Which box would you like to check? (1-9) ");
    int checkedBox;
    std::cin >> checkedBox;
    if (board[checkedBox - 1]) {
        std::println("The box is already taken by you!");
        move(enemy);
    } else if (enemy.getBoard()[checkedBox - 1]) {
        std::println("The box is already taken by the AI!");
        move(enemy);
    } else {
        board[checkedBox - 1] = true;
    }
}

bool Player::checkForWinningRow(const std::bitset<9> &board) {
    const std::bitset<9> winningPattern[8] = {
        0b111000000, 0b000111000, 0b000000111, // horizontal
        0b100100100, 0b010010010, 0b001001001, // vertical
        0b100010001, 0b001010100 // diagonal
    };
    // lay the position pattern over the winning pattern and if the winning pattern in contained in the current position one, return true
    for (std::bitset<9> pattern: winningPattern) {
        if ((board & pattern) == pattern) return true;
    }
    return false;
}

bool Player::checkForDraw(const std::bitset<9> &board1, const std::bitset<9> &board2) {
    std::bitset<9> possiblePosition1 = board2;
    std::bitset<9> possiblePosition2 = board1;
    // by flipping the opponent positions you get your still possible positions, if those contain a winning pattern, then there is no draw
    if (checkForWinningRow(possiblePosition1.flip()) || checkForWinningRow(possiblePosition2.flip())) return false;
    return true;
}

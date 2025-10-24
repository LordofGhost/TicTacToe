#include "TicTacToe.h"

#include <iostream>

#include "Enemy.h"

int main() {
    TicTacToe ticTacToe{};

    return 0;
}

TicTacToe::TicTacToe() {
    std::print("Welcome to Tic Tac Toe!\nWho should start? (1:Player, 0:AI) ");

    if (std::cin.get() == 49) {
        playerFirst = true;
    } else {
        playerFirst = false;
    }

    game();
}

void TicTacToe::game() {
    while (isGameRunning()) {
        if (playerFirst) {
            std::cout << board.toString() << std::endl;

            playerMove();
            if (!isGameRunning()) continue;
            Enemy::move(board);
        } else {
            Enemy::move(board);
            if (!isGameRunning()) continue;

            std::cout << board.toString() << std::endl;

            playerMove();
        }
    }

    std::cout << board.toString() << std::endl;

    printResult();
}

void TicTacToe::printResult() const {
    if (board.hasWon(Board::Player::X)) {
        std::cout << "You won!" << std::endl;
    } else if (board.hasWon(Board::Player::O)) {
        std::cout << "The AI won!" << std::endl;
    } else if (board.isDraw()) {
        std::cout << "It's a draw!" << std::endl;
    }
}

bool TicTacToe::isGameRunning() const {
    if (board.winner() == std::nullopt && !board.isDraw())
        return true;
    return false;
}

void TicTacToe::playerMove() {
    std::print("Which box would you like to check? (1-9) ");
    int checkedBox;
    std::cin >> checkedBox;

    if (!board.isCellEmpty(checkedBox - 1)) {
        std::println("The box is already taken !");
        playerMove();
    } else {
        board.makeMove(checkedBox - 1, Board::Player::X);
    }
}

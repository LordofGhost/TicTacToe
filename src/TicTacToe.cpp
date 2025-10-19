#include "TicTacToe.h"

#include <iostream>

#include "Player.h"
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
            printBoard();

            player.move(enemy);
            if (!isGameRunning()) continue;
            enemy.move(player);
        } else {
            enemy.move(player);
            if (!isGameRunning()) continue;

            printBoard();

            player.move(enemy);
        }
    }

    printBoard();

    printResult();
}

void TicTacToe::printBoard() {
    char position[9];

    for (int i = 0; i < 9; i++) {
        if (enemy.getBoard()[i] == 1) {
            position[i] = '0';
        } else if (player.getBoard()[i] == 1) {
            position[i] = 'X';
        } else {
            position[i] = ' ';
        }
    }

    std::println("   |   |   ");
    std::println(" {} | {} | {} ", position[0], position[1], position[2]);
    std::println("___|___|___");
    std::println("   |   |   ");
    std::println(" {} | {} | {} ", position[3], position[4], position[5]);
    std::println("___|___|___");
    std::println("   |   |   ");
    std::println(" {} | {} | {} ", position[6], position[7], position[8]);
    std::println("   |   |   ");
}

void TicTacToe::printResult() {
    if (Player::checkForWinningRow(player.getBoard())) {
        std::cout << "You won!" << std::endl;
    } else if (Player::checkForWinningRow(enemy.getBoard())) {
        std::cout << "The AI won!" << std::endl;
    } else if (Player::checkForDraw(player.getBoard(), enemy.getBoard())) {
        std::cout << "It's a draw!" << std::endl;
    }
}

bool TicTacToe::isGameRunning() {
    if (!Player::checkForWinningRow(player.getBoard()) && !Player::checkForWinningRow(enemy.getBoard()) && !
        Player::checkForDraw(player.getBoard(), enemy.getBoard()))
        return true;
    return false;
}

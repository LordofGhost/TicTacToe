#include "main.h"

int main() {
    std::bitset<9> boardAi(0);
    std::bitset<9> boardPlayer(0);
    char boardInChar[9];
    bool playerFirst;

    std::cout << "Welcome to Tic Tac Toe!" << std::endl << "Who should start? (1:Player, 0:AI) ";
    std::cin >> playerFirst;

    while (isGameRunning(boardPlayer, boardAi)) {
        if (playerFirst) {
            convertBoard(boardAi, boardPlayer, boardInChar);
            printBoard3x3(boardInChar);

            playerMove(boardPlayer, boardAi);
            if (!isGameRunning(boardPlayer, boardAi)) continue;
            boardAi = Enemy::aiMove(boardAi, boardPlayer);
        } else {
            boardAi = Enemy::aiMove(boardAi, boardPlayer);
            if (!isGameRunning(boardPlayer, boardAi)) continue;

            convertBoard(boardAi, boardPlayer, boardInChar);
            printBoard3x3(boardInChar);

            playerMove(boardPlayer, boardAi);
        }
    }

    convertBoard(boardAi, boardPlayer, boardInChar);
    printBoard3x3(boardInChar);

    // output game result
    if (Logic::checkForWinningRow(boardPlayer)) {
        std::cout << "You won!" << std::endl;
    } else if (Logic::checkForWinningRow(boardAi)) {
        std::cout << "The AI won!" << std::endl;
    } else if (Logic::checkForDraw(boardPlayer, boardAi)) {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

// set char array according to player positions
void convertBoard(std::bitset<9> & boardAi, std::bitset<9> & boardPlayer, char* boardInChar) {
    for (int i = 0; i < 9; i++) {
        if (boardAi[i] == 1) {
            boardInChar[i] = '0';
        } else if (boardPlayer[i] == 1) {
            boardInChar[i] = 'X';
        } else {
            boardInChar[i] = ' ';
        }
    }
}

// CLI output
void printBoard3x3(const char* position) {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", position[0], position[1], position[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", position[3], position[4], position[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", position[6], position[7], position[8]);
    printf("   |   |   \n");
}

void playerMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget) {
    std::cout << "Which box would you like to check? (1-9) " ;
    int checkedBox;
    std::cin >> checkedBox;
    if (boardSelf[checkedBox - 1]) {
        std::cout << "The box is already taken by you!" << std::endl;
        playerMove(boardSelf, boardTarget);
    } else if (boardTarget[checkedBox - 1]) {
        std::cout << "The box is already taken by the AI!" << std::endl;
        playerMove(boardSelf, boardTarget);
    } else {
        boardSelf[checkedBox - 1] = true;
    }
}

bool isGameRunning(std::bitset<9> & boardPlayer, std::bitset<9> & boardAi) {
    //if (boardPlayer.count() < 3 && boardAi.count() < 3) return true;
    if (!Logic::checkForWinningRow(boardPlayer) && !Logic::checkForWinningRow(boardAi) && !Logic::checkForDraw(boardPlayer, boardAi)) return true;
    return false;
}
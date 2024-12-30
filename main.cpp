#include <iostream>
#include <bitset>
#include <cstdlib>
#include <ctime>

void playerMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget);
void aiMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget);
void convertBoard(std::bitset<9> & boardAi, std::bitset<9> & boardPlayer, char* boardInChar);
void printBoard3x3(const char* position);
bool checkForRow(std::bitset<9> & board);
bool isGameRunning(std::bitset<9> & boardPlayer, std::bitset<9> & boardAi);
bool isPlayerWinner(std::bitset<9> & boardPlayer);

int main() {
    std::bitset<9> boardAi(0);
    std::bitset<9> boardPlayer(0);
    char boardInChar[9];

    std::cout << "Welcome to Tic Tac Toe!" << std::endl << "You: X\nAI: 0\n";

    while (isGameRunning(boardPlayer, boardAi)) {
        convertBoard(boardAi, boardPlayer, boardInChar);
        printBoard3x3(boardInChar);

        playerMove(boardPlayer, boardAi);
        aiMove(boardAi, boardPlayer);
    }

    convertBoard(boardAi, boardPlayer, boardInChar);
    printBoard3x3(boardInChar);

    if (isPlayerWinner(boardPlayer)) {
        std::cout << "You won!" << std::endl;
    } else {
        std::cout << "The AI won!" << std::endl;
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
    } else {
        boardSelf[checkedBox - 1] = true;
    }
}

void aiMove(std::bitset<9> & boardSelf, std::bitset<9> & boardTarget) {
    std::srand(static_cast<unsigned>(std::time(0)));
    int checkedbox = std::rand() % 9 + 1;

    if (boardSelf[checkedbox - 1]) {
        std::cout << "The box is already taken by you!" << std::endl;
        playerMove(boardSelf, boardTarget);
    } else if (boardTarget[checkedbox - 1]) {
        std::cout << "The box is already taken by the AI!" << std::endl;
    } else {
        boardSelf[checkedbox - 1] = true;
    }
}

bool checkForRow(std::bitset<9> & board) {

    const std::bitset<9> rows[8] = {0b1110000,0b000111000,0b000000111, // horizontal
                                    0b100100100,0b010010010,0b001001001, // vertical
                                    0b100010001,0b001010100}; // diagonal
    // lay the position pattern over the winning pattern and if the winning pattern in contained in the current position one, return true
    for (std::bitset<9> row : rows) {
        if ((board & row) == row) return true;
    }
    return false;
}

bool isGameRunning(std::bitset<9> & boardPlayer, std::bitset<9> & boardAi) {
    if (boardPlayer.count() < 3 && boardAi.count() < 3) return true;
    if (checkForRow(boardPlayer) == false && checkForRow(boardAi) == false) return true;
    return false;
}

bool isPlayerWinner(std::bitset<9> & boardPlayer) {
    if (boardPlayer.count() < 3) return false;
    if (checkForRow(boardPlayer)) return true;
    return false;
}

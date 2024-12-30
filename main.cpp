#include <iostream>
#include <bitset>

int playerMove();
int aiMove();
void convertBoard(std::bitset<9> boardAi, std::bitset<9> boardPlayer, char* boardInChar);
void printBoard3x3(char* position);

int main() {
    std::bitset<9> boardAi;
    std::bitset<9> boardPlayer;

    char boardInChar[9];
    convertBoard(boardAi, boardPlayer, boardInChar);
    printBoard3x3(boardInChar);

    return 0;
}

// set char array according to player positions
void convertBoard(std::bitset<9> boardAi, std::bitset<9> boardPlayer, char* boardInChar) {
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
void printBoard3x3(char* position) {
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
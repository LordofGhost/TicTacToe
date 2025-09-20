#include "Enemy.h"

#include <random>

#include "Logic.h"

void Enemy::aiMove(std::bitset<9> &boardSelf, const std::bitset<9> &boardTarget) {
    // check if empty board
    if (boardTarget.count() == 0) {
        // Generate random number between 0 and 8
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, 8);
        const int startPosition = dist(rng);

        boardSelf.flip(startPosition);
        return;
    }

    const std::vector<std::bitset<9> > moves = generateMoves(boardSelf, boardTarget);
    int highScore = -99999999;
    for (std::bitset<9> move: moves) {
        int score = max(move, boardTarget, 1);
        if (score > highScore) {
            boardSelf = move;
            highScore = score;
        }
    }
}

int Enemy::max(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth) {
    // if the game ends with this move, give it a score
    if (Logic::checkForWinningRow(boardSelf)) return (500 / depth);
    if (Logic::checkForDraw(boardSelf, boardTarget)) return 0;

    // create all possible enemy moves
    std::vector<std::bitset<9> > moves = generateMoves(boardTarget, boardSelf);
    // go over the enemy moves and find the one worst for the AI
    int lowestScore = 99999999;
    for (std::bitset<9> move: moves) {
        int score = min(move, boardSelf, depth++);
        if (score < lowestScore) {
            lowestScore = score;
        }
    }
    return lowestScore;
}

int Enemy::min(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth) {
    // evaluation of move
    if (Logic::checkForWinningRow(boardSelf)) return -(500 / depth);
    if (Logic::checkForDraw(boardSelf, boardTarget)) return 0;

    // create all possible AI moves, after that enemy move
    std::vector<std::bitset<9> > moves = generateMoves(boardTarget, boardSelf);
    int highestScore = -99999999;
    for (std::bitset<9> move: moves) {
        int score = max(move, boardSelf, depth++);
        if (score > highestScore) {
            highestScore = score;
        }
    }
    return highestScore;
}

std::vector<std::bitset<9> > Enemy::generateMoves(const std::bitset<9> myBoard, const std::bitset<9> enemyBoard) {
    // flipped taken positions from both players together
    std::bitset<9> freePositions = ~(myBoard | enemyBoard);
    std::vector<std::bitset<9> > moves;

    for (int bitCounter = 0; bitCounter < 9; bitCounter++) {
        if (freePositions.test(bitCounter)) {
            moves.push_back(myBoard);
            moves.back()[bitCounter] = true;
            freePositions[bitCounter] = false;
        }
    }
    return moves;
}

#include "Enemy.h"

#include <random>
#include <limits>
#include <algorithm>

#include "Logic.h"

std::bitset<9> Enemy::aiMove(const std::bitset<9> &boardSelf, const std::bitset<9> &boardTarget) {
    std::bitset<9> finalBoard(0);

    // When the AI starts, generate a random start position
    if (boardTarget.count() == 0) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution dist(0, 8);
        const int startPosition = dist(rng);

        return finalBoard.flip(startPosition);
    }

    // Generate all possible moves
    const std::vector<std::bitset<9> > moves = generateMoves(boardSelf, boardTarget);

    int highScore = std::numeric_limits<int>::min();

    // Go over every possible move and evaluate them with a score
    for (const std::bitset move: moves) {
        int score = negamax(move, boardTarget, 1);
        if (score > highScore) {
            finalBoard = move;
            highScore = score;
        }
    }

    return finalBoard;
}

int Enemy::negamax(std::bitset<9> boardSelf, std::bitset<9> boardTarget, int depth) {
    // evaluation of move
    if (Logic::checkForWinningRow(boardSelf)) return 500 / depth;
    if (Logic::checkForDraw(boardSelf, boardTarget)) return 0;

    // Create all possible moves, go over them, update highestScore
    int highestScore = std::numeric_limits<int>::min();
    for (std::bitset move: generateMoves(boardTarget, boardSelf)) {
        int score = -negamax(move, boardSelf, depth++);

        if (score > highestScore) highestScore = score;
    }

    // Return the highest score
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

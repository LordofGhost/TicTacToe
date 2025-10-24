#include "Enemy.h"

#include <random>
#include <iostream>
#include <ostream>

void Enemy::move(Board &board) {
    i = 1;
    // When the AI starts, generate a random start position
    if (board.isEmpty()) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution dist(0, 8);
        const int startPosition = dist(rng);

        board.makeMove(startPosition, Board::Player::O);
        return;
    }

    int bestScore = -EVAL_INFINITE;
    std::pair<int, int> bestMove = {-1, -1};

    for (const auto &move: board.availableMoves()) {
        board.makeMove(move.first, move.second, Board::Player::O);

        int score = -negamax(board, Board::otherPlayer(Board::Player::O), 8);


        board.unmakeMove(move.first, move.second, Board::Player::O);

        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    if (bestMove.first >= 0) {
        board.makeMove(bestMove.first, bestMove.second, Board::Player::O);
    } else {
        std::cerr << "No move found!" << std::endl;
    }
}

int Enemy::negamax(Board &board, const Board::Player &p, const int &depth) {
    // Check for terminal node
    if (board.hasWon(p)) return EVAL_MATE + depth;
    if (board.isDraw() || depth <= 0) return 0;

    int best = -EVAL_INFINITE;

    for (const auto &move: board.availableMoves()) {
        board.makeMove(move.first, move.second, p);

        int score = -negamax(board, Board::otherPlayer(p), depth - 1);

        board.unmakeMove(move.first, move.second, p);

        if (score > best) best = score;
    }

    return best;
}

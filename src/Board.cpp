#include "Board.h"

#include <iostream>
#include <array>

bool Board::inBounds(int row, int col) {
    if (row >= 0 && row <= 2 && col >= 0 && col <= 2) return true;
    return false;
}

int Board::idx(int row, int col) {
    return row * 3 + col;
}

std::uint16_t Board::bits(Player p) const {
    return static_cast<std::uint16_t>(
        p == Player::X ? x.to_ulong() : o.to_ulong()
    );
}

void Board::reset() {
    x.reset();
    o.reset();
}

bool Board::makeMove(int row, int col, Player p) {
    if (!inBounds(row, col)) return false;
    const int i = idx(row, col);
    if (!isCellEmpty(row, col)) return false;
    if (p == Player::X) x.set(static_cast<size_t>(i));
    else o.set(static_cast<size_t>(i));
    return true;
}

bool Board::makeMove(int idx, Player p) {
    auto temp = idxInvert(idx);
    int row = temp.first;
    int col = temp.second;

    return makeMove(row, col, p);
}

bool Board::unmakeMove(int row, int col, Player p) {
    if (!inBounds(row, col)) return false;
    const int i = idx(row, col);
    if (p == Player::X) {
        if (!x.test(static_cast<size_t>(i))) return false;
        x.reset(static_cast<size_t>(i));
    } else {
        if (!o.test(static_cast<size_t>(i))) return false;
        o.reset(static_cast<size_t>(i));
    }
    return true;
}

char Board::at(int row, int col) const {
    if (!inBounds(row, col)) {
        std::cerr << "Not in bounds!";
        return false;
    }
    const int i = idx(row, col);
    if (x.test(static_cast<size_t>(i))) return 'X';
    if (o.test(static_cast<size_t>(i))) return 'O';
    return ' ';
}

bool Board::isCellEmpty(int row, int col) const {
    if (!inBounds(row, col)) return false;
    const int i = idx(row, col);
    return !(x.test(static_cast<size_t>(i)) || o.test(static_cast<size_t>(i)));
}

bool Board::isCellEmpty(int idx) const {
    auto temp = idxInvert(idx);
    int row = temp.first;
    int col = temp.second;

    return isCellEmpty(row, col);
}

std::vector<std::pair<int, int> > Board::availableMoves() const {
    std::vector<std::pair<int, int> > moves;
    std::bitset<9> mergedBoard = x | o;
    for (int i = 0; i < 9; ++i) {
        if (!mergedBoard.test(static_cast<size_t>(i))) {
            moves.emplace_back(i / 3, i % 3);
        }
    }
    return moves;
}

bool Board::hasWon(Player p) const {
    const std::uint16_t m = bits(p);
    for (auto w: WIN_MASKS) {
        if ((m & w) == w) return true;
    }
    return false;
}

std::optional<Board::Player> Board::winner() const {
    if (hasWon(Player::X)) return Player::X;
    if (hasWon(Player::O)) return Player::O;
    return std::nullopt;
}

bool Board::isFull() const {
    return x.count() + o.count() == 9;
}

bool Board::isEmpty() const {
    return x.count() + o.count() == 0;
}

bool Board::isDraw() const {
    if (isFull() && !winner().has_value()) return true;

    // Check if winning is still possible
    const std::uint16_t emptyMask = static_cast<std::uint16_t>((~(x | o)).to_ulong());

    for (Player p : {Player::X, Player::O}) {
        const std::uint16_t m = bits(p);
        for (auto w : WIN_MASKS) {
            if (((m | emptyMask) & w) == w) {
                return false;
            }
        }
    }

    return false;
}

std::string Board::toString() const {
    std::string s;
    for (int r = 0; r < 3; ++r) {
        if (r) s += "-+-+-\n";
        for (int c = 0; c < 3; ++c) {
            if (c) s += '|';
            s += at(r, c);
        }
        s += '\n';
    }
    return s;
}

std::pair<int, int> Board::idxInvert(int idx) {
    return {idx / 3, idx % 3};
}

Board::Player Board::otherPlayer(Player p) {
    if (Player::O == p) return Player::X;
    return Player::O;
}

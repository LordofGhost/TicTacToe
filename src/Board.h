#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <optional>
#include <bitset>
#include <vector>

class Board {
    static constexpr std::array<std::uint16_t, 8> WIN_MASKS{
        0b000000111, // Row 0
        0b000111000, // Row 1
        0b111000000, // Row 2
        0b001001001, // Col 0
        0b010010010, // Col 1
        0b100100100, // Col 2
        0b100010001, // Diag
        0b001010100 // Anti-diag
    };

    std::bitset<9> x;
    std::bitset<9> o;

    static bool inBounds(int row, int col);

    static int idx(int row, int col);

public:
    enum class Player { X, O };

    Board() = default;

    void reset();

    bool makeMove(int row, int col, Player p);

    bool makeMove(int idx, Player p);

    bool unmakeMove(int row, int col, Player p);

    [[nodiscard]] char at(int row, int col) const;

    [[nodiscard]] bool isCellEmpty(int row, int col) const;

    [[nodiscard]] bool isCellEmpty(int idx) const;

    [[nodiscard]] std::vector<std::pair<int, int> > availableMoves() const;

    [[nodiscard]] bool hasWon(Player p) const;

    [[nodiscard]] std::optional<Player> winner() const;

    [[nodiscard]] bool isFull() const;

    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] bool isDraw() const;

    [[nodiscard]] std::string toString() const;

    static std::pair<int, int> idxInvert(int idx);

    static Player otherPlayer(Player p);

private:
    [[nodiscard]] std::uint16_t bits(Player p) const;
};


#endif //TICTACTOE_BOARD_H

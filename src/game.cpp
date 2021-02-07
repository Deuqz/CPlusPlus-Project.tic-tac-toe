#include "game.h"
#include <vector>

namespace tictactoe {
namespace {
const std::vector<std::pair<int, int>> ways_of_movement = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
// File-local declarations and definitions.
}  // namespace

Game::Game() {
    field.resize(HEIGHT, std::vector<char>(WIDTH, '.'));
    size_free_field = HEIGHT * WIDTH;
    gamer = false;
}

char Game::get_gamer_name() const {
    return gamer ? 'X' : 'O';
}

void Game::change_gamer_name() {
    gamer = !gamer;
}

bool Game::is_move_valid(int x, int y) const {
    return x >= 0 && y >= 0 && field[x][y] == '.';
}

void Game::make_move(int x, int y) {
    field[x][y] = get_gamer_name();
    --size_free_field;
}

bool Game::has_winner(int x, int y) const {
    bool win = false;
    for (int i = 0; i < 7; i += 2) {
        win |= (Game::count_signs(ways_of_movement[i], x, y) +
                    Game::count_signs(ways_of_movement[i + 1], x, y) >=
                ROW_TO_WIN - 1);
    }
    return win;
}

int Game::count_signs(std::pair<int, int> moving_to, int x, int y) const {
    int sum = 0;
    while (0 <= x + moving_to.first && x + moving_to.first <= 9 &&
           0 <= y + moving_to.second && y + moving_to.second <= 9) {
        x += moving_to.first;
        y += moving_to.second;
        if (field[x][y] == get_gamer_name()) {
            ++sum;
        } else {
            break;
        }
    }
    return sum;
}

bool Game::is_draw() const {
    return size_free_field == 0;
}

// Functions for testing
std::vector<std::vector<char>> &Game::get_field() {
    return field;
}

int Game::get_size_free_field() const {
    return size_free_field;
}

// Externally visible declarations and definitions.
}  // namespace tictactoe

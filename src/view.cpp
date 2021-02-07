#include "view.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include "cassert"
#include "game.h"

namespace tictactoe {
namespace {}

View::View(Game &game_, std::istream &is_, std::ostream &os_)
    : game(game_), is(is_), os(os_) {
    write_mode();
    os << "O move: ";
}

void View::play() {
    bool contin = true;
    while (contin) {
        contin = game_step();
    }
}

bool View::game_step() {
    is >> s1 >> s2;

    if (incorrect_input(s1) || incorrect_input(s2)) {
        os << "Bad move!\n" << game.get_gamer_name() << " move: ";
        return true;
    }
    int x = make_coord(s1);
    int y = make_coord(s2);
    if (x == -1 && y == -1) {
        return false;
    } else if (!game.is_move_valid(x, y)) {
        os << "Bad move!\n" << game.get_gamer_name() << " move: ";
        return true;
    }

    game.make_move(x, y);
    if (game.has_winner(x, y)) {
        write_field();
        os << game.get_gamer_name() << " wins!\n";
        return false;
    } else if (game.is_draw()) {
        write_field();
        os << "Draw\n";
        return false;
    } else {
        write_mode();
        game.change_gamer_name();
        os << game.get_gamer_name() << " move: ";
        return true;
    }
}

bool View::incorrect_input(const std::string &str) {
    std::string s;
    for (char i : str) {
        if (i != ' ') {
            s += i;
        }
    }
    assert(!s.empty());
    if (((s[0] < '0' || s[0] > '9') && (s[0] != '-')) ||
        (s[0] == '-' && s.size() == 1)) {
        return true;
    }
    for (unsigned int i = 1; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return true;
        }
    }
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (s[i] != '0' && s[i] != '-') {
            return i != s.size() - 1;
        }
    }
    return false;
}

int View::make_coord(const std::string &s) {
    return s[0] == '-' ? -(s[s.size() - 1] - '0') : s[s.size() - 1] - '0';
}

void View::write_field() {
    os << "\n";
    for (int i = 0; i < tictactoe::Game::HEIGHT; ++i) {
        for (int j = 0; j < tictactoe::Game::WIDTH; ++j) {
            os << game.get_field()[i][j];
        }
        os << "\n";
    }
}
}  // namespace tictactoe

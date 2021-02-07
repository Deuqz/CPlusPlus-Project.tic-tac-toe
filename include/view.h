#ifndef VIEW_H_
#define VIEW_H_

#include <sstream>
#include <string>
#include "game_fwd.h"

namespace tictactoe {
struct View {
private:
    Game &game;
    std::string s1, s2;
    std::istream &is;
    std::ostream &os;

    void write_field();

    void write_mode();

public:
    explicit View(Game &game_, std::istream &is_, std::ostream &os_);

    void play();

    bool game_step();

    static bool incorrect_input(const std::string &s);

    static int make_coord(const std::string &s);
};
}  // namespace tictactoe

#endif  // VIEW_H_

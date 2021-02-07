#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "game_fwd.h"

namespace tictactoe {
struct Game {
    static const int HEIGHT = 10;
    static const int WIDTH = 10;
    static const int ROW_TO_WIN = 5;

private:
    bool gamer;
    int size_free_field;
    std::vector<std::vector<char>> field;

public:
    Game();

    [[nodiscard]] char get_gamer_name() const;

    void change_gamer_name();

    [[nodiscard]] bool is_move_valid(int x, int y) const;

    void make_move(int x, int y);

    [[nodiscard]] bool has_winner(int x, int y) const;

    //Следующая функция возвращает количество знаков, совпадающих с gamer_name,
    //если двигаться в направлении moving_to от точки (x, y)
    [[nodiscard]] int count_signs(std::pair<int, int> moving_to,
                                  int x,
                                  int y) const;

    [[nodiscard]] bool is_draw() const;

    // Functions required for testing
    std::vector<std::vector<char>> &get_field();

    [[nodiscard]] int get_size_free_field() const;
};
}  // namespace tictactoe

#endif  // GAME_H_

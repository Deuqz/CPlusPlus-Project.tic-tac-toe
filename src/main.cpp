#include <iostream>
#include "game.h"
#include "view.h"

int main() {
    tictactoe::Game game{};
    tictactoe::View view(game, std::cin, std::cout);
    view.play();
}

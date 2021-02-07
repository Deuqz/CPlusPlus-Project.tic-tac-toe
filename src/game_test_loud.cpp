#include <iostream>
#include "game.h"
#include "mytest.h"
#include "view.h"

namespace testing {

void clear_streams(std::stringstream &in, std::stringstream &out) {
    out.str("");
    out.clear();
    in.str("");
    in.clear();
}

TEST_CASE("Test view game steps") {
    tictactoe::Game game{};
    std::stringstream ss_in;
    std::stringstream ss_out;
    tictactoe::View view(game, ss_in, ss_out);

    CHECK(ss_out.str() ==
          "\n..........\n..........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 0";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nO.........\n..........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "001 00";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nO.........\nX.........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "000001 -000";
    view.game_step();

    CHECK(ss_out.str() == "Bad move!\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 1";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOO........\nX.........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 0a1";
    view.game_step();

    CHECK(ss_out.str() == "Bad move!\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 1";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOO........\nXX........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 2";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOO.......\nXX........\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 2";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOO.......\nXXX.......\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 3";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOOO......\nXXX.......\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 3";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOOO......\nXXXX......\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 4";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOOOO.....\nXXXX......\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO wins!\n");
}
}  // namespace testing
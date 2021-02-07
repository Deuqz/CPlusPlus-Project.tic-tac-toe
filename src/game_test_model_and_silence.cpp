#include "game.h"
#include "mytest.h"
#include "vector"
#include "view.h"

namespace testing {
TEST_CASE("Test model constructor") {
    tictactoe::Game game{};
    CHECK(game.get_size_free_field() == 100);
    CHECK(game.get_gamer_name() == 'O');
    std::vector<std::vector<char>> temp = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };
    CHECK(game.get_field() == temp);
}

TEST_CASE("Test model get_gamer_name and change_gamer_name") {
    tictactoe::Game game{};
    CHECK(game.get_gamer_name() == 'O');
    game.change_gamer_name();
    CHECK(game.get_gamer_name() == 'X');
}

TEST_CASE("Test model make_move") {
    tictactoe::Game game{};
    game.make_move(0, 0);
    game.change_gamer_name();
    game.make_move(1, 0);
    game.change_gamer_name();
    game.make_move(2, 0);
    game.change_gamer_name();
    game.make_move(3, 0);
    game.change_gamer_name();
    std::vector<std::vector<char>> temp = {
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_field() == temp);
}

TEST_CASE("Test model is_move_valid") {
    tictactoe::Game game{};
    CHECK(game.is_move_valid(-1, 0) == false);
    CHECK(game.is_move_valid(0, -1) == false);
    CHECK(game.is_move_valid(-2, -2) == false);
    CHECK(game.is_move_valid(0, 0) == true);
    game.make_move(0, 0);
    game.change_gamer_name();
    CHECK(game.is_move_valid(1, 0) == true);
    game.make_move(1, 0);
    game.change_gamer_name();
    CHECK(game.is_move_valid(2, 0) == true);
    game.make_move(2, 0);
    game.change_gamer_name();
    CHECK(game.is_move_valid(3, 0) == true);
    game.make_move(3, 0);
    game.change_gamer_name();
    std::vector<std::vector<char>> temp = {
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_field() == temp);
    CHECK(game.is_move_valid(0, 0) == false);
    CHECK(game.is_move_valid(1, 0) == false);
    game.change_gamer_name();
    CHECK(game.is_move_valid(0, 0) == false);
    CHECK(game.is_move_valid(1, 0) == false);
}

TEST_CASE("Test model count_signs") {
    tictactoe::Game game{};
    game.make_move(0, 0);
    game.change_gamer_name();
    game.make_move(1, 0);
    game.change_gamer_name();
    game.make_move(2, 0);
    game.change_gamer_name();
    game.make_move(3, 0);
    game.change_gamer_name();
    std::vector<std::vector<char>> temp = {
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_field() == temp);
    CHECK(game.count_signs(std::make_pair(-1, -1), 1, 1) == 1);
    CHECK(game.count_signs(std::make_pair(1, -1), 1, 1) == 1);
    CHECK(game.count_signs(std::make_pair(0, -1), 1, 1) == 0);
    CHECK(game.count_signs(std::make_pair(0, 1), 1, 1) == 0);
    game.make_move(0, 2);
    game.change_gamer_name();
    game.make_move(1, 2);
    game.change_gamer_name();
    game.make_move(0, 3);
    game.change_gamer_name();
    game.make_move(1, 3);
    game.change_gamer_name();
    game.make_move(0, 5);
    game.change_gamer_name();
    game.make_move(1, 5);
    game.change_gamer_name();
    temp = {{'O', '.', 'O', 'O', '.', 'O', '.', '.', '.', '.'},
            {'X', '.', 'X', 'X', '.', 'X', '.', '.', '.', '.'},
            {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_field() == temp);
    CHECK(game.count_signs(std::make_pair(0, -1), 0, 4) == 2);
    CHECK(game.count_signs(std::make_pair(0, 1), 0, 4) == 1);
    CHECK(game.count_signs(std::make_pair(-1, 0), 0, 4) == 0);
    game.make_move(0, 6);
    game.change_gamer_name();
    game.make_move(1, 6);
    game.change_gamer_name();
    temp = {{'O', '.', 'O', 'O', '.', 'O', 'O', '.', '.', '.'},
            {'X', '.', 'X', 'X', '.', 'X', 'X', '.', '.', '.'},
            {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_field() == temp);
    CHECK(game.count_signs(std::make_pair(0, 1), 0, 4) == 2);
    game.change_gamer_name();
    CHECK(game.count_signs(std::make_pair(0, 1), 1, 4) == 2);
}

TEST_CASE("Test model has_winner") {
    tictactoe::Game game{};
    std::vector<std::vector<char>> temp = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 100);
    CHECK(game.get_field() == temp);
    CHECK(game.is_move_valid(0, 0) == true);
    CHECK(game.get_field() == temp);
    game.make_move(0, 0);
    game.change_gamer_name();
    temp = {{'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 99);
    CHECK(game.get_field() == temp);
    game.make_move(1, 0);
    game.change_gamer_name();
    temp = {{'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'X', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 98);
    CHECK(game.get_field() == temp);
    game.make_move(0, 1);
    game.change_gamer_name();
    game.make_move(1, 1);
    game.change_gamer_name();
    game.make_move(0, 2);
    game.change_gamer_name();
    game.make_move(1, 2);
    game.change_gamer_name();
    game.make_move(0, 3);
    game.change_gamer_name();
    game.make_move(1, 3);
    game.change_gamer_name();
    temp = {{'O', 'O', 'O', 'O', '.', '.', '.', '.', '.', '.'},
            {'X', 'X', 'X', 'X', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.has_winner(0, 3) == false);
    CHECK(game.has_winner(0, 0) == false);
    CHECK(game.has_winner(1, 3) == false);
    CHECK(game.has_winner(1, 0) == false);
    CHECK(game.get_size_free_field() == 92);
    CHECK(game.get_field() == temp);
    game.make_move(0, 4);
    temp = {{'O', 'O', 'O', 'O', 'O', '.', '.', '.', '.', '.'},
            {'X', 'X', 'X', 'X', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 91);
    CHECK(game.get_field() == temp);
    CHECK(game.has_winner(0, 4) == true);
}

TEST_CASE("Test model is_draw") {
    tictactoe::Game game{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; j += 2) {
            game.make_move(i, j);
            game.change_gamer_name();
            game.make_move(i, j + 1);
            game.change_gamer_name();
        }
    }
    std::vector<std::vector<char>> temp = {
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 60);
    CHECK(game.get_field() == temp);
    game.make_move(9, 0);
    game.change_gamer_name();
    for (int i = 4; i < 8; ++i) {
        for (int j = 0; j < 10; j += 2) {
            game.make_move(i, j);
            game.change_gamer_name();
            game.make_move(i, j + 1);
            game.change_gamer_name();
        }
    }
    temp = {{'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'O', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    CHECK(game.get_size_free_field() == 19);
    CHECK(game.get_field() == temp);
    game.make_move(9, 1);
    game.change_gamer_name();
    for (int j = 0; j < 10; j += 2) {
        game.make_move(8, j);
        game.change_gamer_name();
        game.make_move(8, j + 1);
        game.change_gamer_name();
    }
    for (int j = 2; j < 8; j += 2) {
        game.make_move(9, j);
        game.change_gamer_name();
        game.make_move(9, j + 1);
        game.change_gamer_name();
    }
    game.make_move(9, 8);
    game.change_gamer_name();
    game.make_move(9, 9);
    game.change_gamer_name();
    temp = {{'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
            {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'}};
    CHECK(game.get_field() == temp);
    CHECK(game.get_size_free_field() == 0);
    CHECK(game.is_draw());
}

TEST_CASE("Test view constructor") {
    tictactoe::Game game{};
    std::stringstream ss_in;
    std::stringstream ss_out;
    tictactoe::View view(game, ss_in, ss_out);
    CHECK(ss_out.str() == "O move: ");
}

TEST_CASE("Test view incorrect_input") {
    tictactoe::Game game{};
    std::stringstream ss_in;
    std::stringstream ss_out;
    tictactoe::View view(game, ss_in, ss_out);
    CHECK(view.incorrect_input("0") == false);
    CHECK(view.incorrect_input("00000") == false);
    CHECK(view.incorrect_input("9") == false);
    CHECK(view.incorrect_input("000003") == false);
    CHECK(view.incorrect_input("  0000003   ") == false);
    CHECK(view.incorrect_input("-00000") == false);
    CHECK(view.incorrect_input("-0000a") == true);
    CHECK(view.incorrect_input("000a") == true);
    CHECK(view.incorrect_input("00a00") == true);
    CHECK(view.incorrect_input("-") == true);
    CHECK(view.incorrect_input("9999999999999999999999999") == true);
    CHECK(view.incorrect_input("1000000000000000000000000") == true);
    CHECK(view.incorrect_input("0000000000000000000100000") == true);
}

TEST_CASE("Test view make_coord") {
    tictactoe::Game game{};
    std::stringstream ss_in;
    std::stringstream ss_out;
    tictactoe::View view(game, ss_in, ss_out);
    CHECK(view.make_coord("0") == 0);
    CHECK(view.make_coord("00000") == 0);
    CHECK(view.make_coord("9") == 9);
    CHECK(view.make_coord("000003") == 3);
    CHECK(view.make_coord("-00000") == 0);
}

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

    CHECK(ss_out.str() == "O move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 0";
    view.game_step();

    CHECK(ss_out.str() == "X move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "001 00";
    view.game_step();

    CHECK(ss_out.str() == "O move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "000001 -000";
    view.game_step();

    CHECK(ss_out.str() == "Bad move!\nO move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 1";
    view.game_step();

    CHECK(ss_out.str() == "X move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 0a1";
    view.game_step();

    CHECK(ss_out.str() == "Bad move!\nX move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 1";
    view.game_step();

    CHECK(ss_out.str() == "O move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 2";
    view.game_step();

    CHECK(ss_out.str() == "X move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 2";
    view.game_step();

    CHECK(ss_out.str() == "O move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 3";
    view.game_step();

    CHECK(ss_out.str() == "X move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "1 3";
    view.game_step();

    CHECK(ss_out.str() == "O move: ");
    clear_streams(ss_in, ss_out);
    ss_in << "0 4";
    view.game_step();

    CHECK(ss_out.str() ==
          "\nOOOOO.....\nXXXX......\n..........\n..........\n..........\n......"
          "....\n..........\n..........\n..........\n..........\nO wins!\n");
}
}  // namespace testing
namespace tictactoe {}  // namespace tictactoe

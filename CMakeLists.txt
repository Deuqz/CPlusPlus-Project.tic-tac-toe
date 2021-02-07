cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/W4 /WX)
    # Do not specify /O2 because there are Debug/Release modes.
else()
    if (NOT DEFINED CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE Debug)  # Add debug information
    endif (NOT DEFINED CMAKE_BUILD_TYPE)

    add_compile_options(-Wall -Wextra -Werror -O2)
    if (UNIX AND NOT DEFINED CMAKE_CXX_FLAGS)  # Do not add if -DCMAKE_CXX_FLAGS is passed
      add_compile_options(-fsanitize=address)
      add_link_options(-fsanitize=address)
    endif (UNIX AND NOT DEFINED CMAKE_CXX_FLAGS)
endif (MSVC)

add_subdirectory(mytest)  # Add only after all compilation options are specified.

include_directories(include)  # Add only after 'mytest' is included, so it's independent.

add_library(common OBJECT src/game.cpp)
target_link_libraries(common mytest)

add_executable(tic-tac-toe-test-model_and_silence src/game_test_model_and_silence.cpp src/view.cpp src/view_cli_silent.cpp)
target_link_libraries(tic-tac-toe-test-model_and_silence mytest-main common)

add_executable(tic-tac-toe-test-loud src/game_test_loud.cpp src/view.cpp src/view_cli_loud.cpp)
target_link_libraries(tic-tac-toe-test-loud mytest-main common)

add_executable(tic-tac-toe-silent src/main.cpp src/game.cpp src/view.cpp src/view_cli_silent.cpp)

add_executable(tic-tac-toe-loud src/main.cpp src/game.cpp src/view.cpp src/view_cli_loud.cpp)

cmake_minimum_required(VERSION 3.10)

project(mytest)

# All compilation options are specified in the root project.

add_library(mytest src/mytest.cpp)
target_include_directories(mytest PUBLIC include)

add_library(mytest-main src/mytest_main.cpp)
target_link_libraries(mytest-main mytest)

add_executable(mytest-demo demo/demo1.cpp demo/demo2.cpp demo/demo3.cpp)
target_link_libraries(mytest-demo mytest-main)

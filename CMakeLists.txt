cmake_minimum_required(VERSION 3.0)

project(main LANGUAGES CXX)

add_executable(main src/main.cc src/shunting-yard.cc)

set(CMAKE_BUILD_TYPE Debug)

include_directories(src)

add_definitions(-Wall -Werror -Wextra -pedantic -std=c++17)

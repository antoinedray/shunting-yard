cmake_minimum_required(VERSION 3.0)

project(bistro LANGUAGES CXX)

add_executable(bistro src/main.cc)

set(CMAKE_BUILD_TYPE Debug)

include_directories(src)

add_definitions(-g -Wall -Werror -Wextra -pedantic -std=c99)

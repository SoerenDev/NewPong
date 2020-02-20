cmake_minimum_required(VERSION 3.15)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp Game.cpp Game.h Ball.cpp Ball.h Paddle.cpp Paddle.h)
target_link_libraries(Pong sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
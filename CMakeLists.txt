cmake_minimum_required(VERSION 3.30)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess src/chess.cpp
        include/Board.h
        include/BoardPiece.h
        src/BoardPiece.cpp
        src/Board.cpp)

#pragma once
#include "BoardPiece.hpp"

const int BOARD_SIZE = 8;

class Board {
public:
  Board();
  void printBoard();

private:
  BoardPiece* m_Board[BOARD_SIZE][BOARD_SIZE];
};

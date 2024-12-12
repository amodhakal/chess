#pragma once
#include "BoardPiece.hpp"

/** Ths size of the board */
const int BOARD_SIZE = 8;

/**
 * Class that represents the chess board
 */
class Board {
public:
  /**
   * Creates the board object
   */
  Board();

  /**
   * Prints the board to the terminal
   */
  void printBoard();

private:
  /** Matrix that points to the board pieces in a chess board */
  BoardPiece *m_Board[BOARD_SIZE][BOARD_SIZE];
};

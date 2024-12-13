#pragma once
#include "BoardPiece.hpp"
#include "Utils.hpp"

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

  /**
   * Moves the piece of the owner based on the movement given. Will print
   * out an error message if an error occured.
   *
   * @param movement is the owner's desired movement
   * @param owner is the owner of the chess piece
   * @return 0 if successful
   *         -1 if the chess piece doesn't exist in starting location
   *         -2 if the owner doesn't own the piece
   */
  int makeOwnerMovement(Movement &movement, Owner owner);

private:
  /** Matrix that points to the board pieces in a chess board */
  BoardPiece *m_Board[BOARD_SIZE][BOARD_SIZE];

  /**
   * Returns the chess piece in the given row and column
   * @param row where the chess piece is located
   * @param col where the chess piece is located
   * @return nullptr if none there, pointer otherwise
   */
  BoardPiece *getChessPiece(int row, int col);
};

//
// Created by Amodh on 12/13/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "BoardPiece.h"

constexpr int BOARD_LENGTH = 8;

typedef BoardPiece *BoardMatrix[BOARD_LENGTH][BOARD_LENGTH];

class Board
{
public:
  Board( const User &bottomUser, const User &topUser );

  void setBoardPiece( BoardPiece *piece, int row, int col );

  BoardPiece *getBoardPiece( int row, int col );

  void printBoard();

  void handleUserInput(User& user);

private:
  BoardMatrix m_Board{};
};

#endif //CHESS_BOARD_H

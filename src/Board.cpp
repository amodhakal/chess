//
// Created by Amodh on 12/13/24.
//

#include "../include/Board.h"
#include <iostream>

constexpr int TOPMOST_ROW = 0;
constexpr int BOTTOMMOST_ROW = 7;

Board::Board( const User &bottomUser, const User &topUser )
{
  for ( auto &row: m_Board ) {
    for ( auto &piece: row ) {
      piece = nullptr;
    }
  }

  for ( int col = 0; col < BOARD_LENGTH; col++ ) {
    m_Board[ TOPMOST_ROW + 1 ][ col ] = new PawnPiece( topUser );
    m_Board[ BOTTOMMOST_ROW - 1 ][ col ] = new PawnPiece( bottomUser );

    BoardPiece **topPiece = &m_Board[ TOPMOST_ROW ][ col ];
    BoardPiece **bottomPiece = &m_Board[ BOTTOMMOST_ROW ][ col ];

    if ( col == 1 || col == 6 ) {
      *topPiece = new KnightPiece( topUser );
      *bottomPiece = new KnightPiece( bottomUser );
      continue;
    }

    if ( col == 2 || col == 5 ) {
      *topPiece = new BishopPiece( topUser );
      *bottomPiece = new BishopPiece( bottomUser );
      continue;
    }

    if ( col == 0 || col == 7 ) {
      *topPiece = new RookPiece( topUser );
      *bottomPiece = new RookPiece( bottomUser );
      continue;
    }

    if ( col == 4 ) {
      *topPiece = new QueenPiece( topUser );
      *bottomPiece = new QueenPiece( bottomUser );
    }

    if ( col == 3 ) {
      *topPiece = new KingPiece( topUser );
      *bottomPiece = new KingPiece( bottomUser );
    }
  }
}

BoardPiece *Board::getBoardPiece( int row, int col )
{
  return Board::m_Board[ row ][ col ];
}

void Board::printBoard()
{
  using namespace std;
  for ( int rowIdx = 0; rowIdx < BOARD_LENGTH; rowIdx++ ) {
    cout << "\n---+---+---+---+---+---+---+---+---\n" << rowIdx + 1 << " |";

    for ( int colIdx = 0; colIdx < BOARD_LENGTH; colIdx++ ) {
      BoardPiece *piece = getBoardPiece( rowIdx, colIdx );
      if ( piece == nullptr ) {
        cout << "   ";
      } else {
        cout << "\033[" << piece->getUser().getOutputColor() << "m "
             << piece->getPieceAsCharacter() << " \033[0m";
      }

      if ( colIdx != BOARD_LENGTH - 1 ) {
        cout << "|";
      }
    }
  }

  cout << "\n";
}

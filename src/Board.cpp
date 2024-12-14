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

void Board::setBoardPiece( BoardPiece *piece, int row, int col )
{
  Board::m_Board[ row ][ col ] = piece;
}

BoardPiece *Board::getBoardPiece( int row, int col )
{
  return Board::m_Board[ row ][ col ];
}

void Board::printBoard()
{
  using namespace std;

  cout << "\n  | A | B | C | D | E | F | G | H ";

  for ( int rowIdx = 0; rowIdx < BOARD_LENGTH; rowIdx++ ) {
    cout << "\n--+---+---+---+---+---+---+---+---\n" << rowIdx + 1 << " |";

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

typedef struct
{
  int startRow;
  int startCol;
  int endRow;
  int endCol;
} PositionChange;

void readUserInputTerminal( const std::string &username, PositionChange *positionChange )
{
  using namespace std;

  handler:
  cout << "\nFor " << username << ", what is the desired position change(XX:XX)?: " << endl;
  string result;
  getline( cin, result );

  if ( result.length() != 5 ) {
    cerr << "Invalid length given, must be in format XX:XX" << endl;
    goto handler;
  }

  int startCol = result[ 0 ] - 'A';
  if ( startCol < 0 || startCol > BOARD_LENGTH - 1 ) {
    cerr << "Expected first character to be capital letters from A-H inclusive" << endl;
    goto handler;
  }

  int startRow = result[ 1 ] - '1';
  if ( startRow < 0 || startRow > BOARD_LENGTH - 1 ) {
    cerr << "Expected second character to be number between 1 and 8 inclusive" << endl;
    goto handler;
  }

  char seperator = result[ 2 ];
  if ( seperator != ':' ) {
    cerr << "Expected third character to be ':'" << endl;
    goto handler;
  }

  int endCol = result[ 3 ] - 'A';
  if ( endCol < 0 || endCol > BOARD_LENGTH - 1 ) {
    cerr << "Expected fourth character to be capital letters from A-H inclusive" << endl;
    goto handler;
  }

  int endRow = result[ 4 ] - '1';
  if ( endRow < 0 || endRow > BOARD_LENGTH - 1 ) {
    cerr << "Expected fifth character to be number between 1 and 8 inclusive" << endl;
    goto handler;
  }

  positionChange->startRow = startRow;
  positionChange->startCol = startCol;
  positionChange->endRow = endRow;
  positionChange->endCol = endCol;
}

void Board::handleUserInput( User &user )
{
  using namespace std;

  handler:

  PositionChange desired;
  readUserInputTerminal( user.getName(), &desired );

  BoardPiece *movingPiece = Board::getBoardPiece( desired.startRow, desired.startCol );
  if ( movingPiece == nullptr ) {
    cerr << "A chess piece in the given location doesn't exist" << endl;
    goto handler;
  }

  if ( movingPiece->getUser() != user ) {
    cerr << "You don't own this piece" << endl;
    goto handler;
  }

  // TODO: Check positions change doable for that specific piece

  Board::setBoardPiece(nullptr, desired.startRow, desired.startCol);
  Board::setBoardPiece( movingPiece, desired.endRow, desired.endCol);
}

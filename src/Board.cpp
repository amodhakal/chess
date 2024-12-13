#include "../include/Board.hpp"

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

/** The row where the computer's main pieces (kings) intiially are */
const int COMPUTER_MAIN_ROW = 0;

/** The row where the player's main peices (kings) initially are  */
const int PLAYER_MAIN_ROW = 7;

Board::Board() {
  // Initializes all the board pieces with a null pointer
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      m_Board[row][col] = nullptr;
    }
  }

  for (int col = 0; col < BOARD_SIZE; col++) {
    // Adds all of the pawns to the chess board with appropriate owner
    m_Board[COMPUTER_MAIN_ROW + 1][col] = new PawnPiece(Owner::Computer);
    m_Board[PLAYER_MAIN_ROW - 1][col] = new PawnPiece(Owner::Player);

    BoardPiece **computerPointer = &m_Board[COMPUTER_MAIN_ROW][col];
    BoardPiece **playerPointer = &m_Board[PLAYER_MAIN_ROW][col];

    // Assign a chess piece with the correct owner
    switch (col) {
    case 0:
    case 7:
      *computerPointer = new RookPiece(Owner::Computer);
      *playerPointer = new RookPiece(Owner::Player);
      break;
    case 1:
    case 6:
      *computerPointer = new KnightPiece(Owner::Computer);
      *playerPointer = new KnightPiece(Owner::Player);
      break;
    case 2:
    case 5:
      *computerPointer = new BishopPiece(Owner::Computer);
      *playerPointer = new BishopPiece(Owner::Player);
      break;
    case 4:
      *computerPointer = new QueenPiece(Owner::Computer);
      *playerPointer = new QueenPiece(Owner::Player);
      break;
    case 3:
      *computerPointer = new KingPiece(Owner::Computer);
      *playerPointer = new KingPiece(Owner::Player);
      break;
    }
  }
}

BoardPiece *Board::getChessPiece(int row, int col) { return (Board::m_Board[row][col]); }

void Board::printBoard() {
  printf("\n   | A | B | C | D | E | F | G | H ");

  for (int row = 0; row < BOARD_SIZE; row++) {
    printf("\n---+---+---+---+---+---+---+---+---\n");
    printf(" %d |", row + 1);
    for (int col = 0; col < BOARD_SIZE; col++) {

      BoardPiece *piece = m_Board[row][col];

      if (piece == nullptr) {
        printf("   ");
      } else {
        // Prints the piece with color { player: red, computer: blue }
        char ch = piece->getChar();
        const char *output = piece->getOwner() == Owner::Player ? " \033[94m%c\033[0m " : " \033[91m%c\033[0m ";

        printf(output, ch);
      }

      if (col != BOARD_SIZE - 1) {
        printf("|");
      }
    }
  }

  printf("\n");
}

int Board::makeOwnerMovement(Movement &movement, Owner owner) {
  // Get chosen chess piece, return -1 if nothing exists there
  BoardPiece *chosenPiece = Board::getChessPiece(movement.startY, movement.startX);
  if (chosenPiece == nullptr) {
    cerr << "There is no pieces here\n";
    return -1;
  }

  // Return -2 if the chosen piece is not owned by the given owner
  if (chosenPiece->getOwner() != owner) {
    cerr << "You don't own this piece" << chosenPiece->getChar() << ", thus can't move it\n"
            "Owned by " << chosenPiece->getOwnerString() << '\n';
    return -2;
  }

  // TODO: Add further checking

  // Move the piece 
  //! Haven't implemented taking a piece, just takes ove the spot right now
  Board::m_Board[movement.startY][movement.startX] = nullptr;
  Board::m_Board[movement.endY][movement.endX] = chosenPiece;
  return 0;
}

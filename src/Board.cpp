#include "../include/Board.hpp"

#include <cstdio>
#include <string>

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
    m_Board[COMPUTER_MAIN_ROW + 1][col] =
        new BoardPiece(Owner::Computer, Rank::Pawn);
    m_Board[PLAYER_MAIN_ROW - 1][col] =
        new BoardPiece(Owner::Player, Rank::Pawn);

    // Figures out the rank of the chess piece
    Rank chosenRank;
    switch (col) {
    case 0:
    case 7:
      chosenRank = Rank::Rook;
      break;
    case 1:
    case 6:
      chosenRank = Rank::Knight;
      break;
    case 2:
    case 5:
      chosenRank = Rank::Bishop;
      break;
    case 3:
      chosenRank = Rank::King;
      break;
    case 4:
      chosenRank = Rank::Queen;
      break;
    }

    // Adds the chess pieces to the chess board with appropriate owner and rank
    m_Board[COMPUTER_MAIN_ROW][col] =
        new BoardPiece(Owner::Computer, chosenRank);
    m_Board[PLAYER_MAIN_ROW][col] = new BoardPiece(Owner::Player, chosenRank);
  }
}

void Board::printBoard() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      BoardPiece *piece = m_Board[row][col];
      char ch;

      // Select a charcter to represent the chess pieces
      //* I couldn't get unicode chess pieces to work,
      //* so I decided to use characters instead
      if (piece != nullptr) {
        switch (piece->getRank()) {
        case Rank::Pawn:
          ch = 'P';
          break;
        case Rank::Knight:
          ch = 'N';
          break;
        case Rank::Bishop:
          ch = 'B';
          break;
        case Rank::Rook:
          ch = 'R';
          break;
        case Rank::Queen:
          ch = 'Q';
          break;
        case Rank::King:
          ch = 'K';
          break;
        }
      }

      // Prints the piece with appropriate color { player: red, computer: lue }
      if (piece == nullptr) {
        printf("   ");
      } else if (piece->getOwner() == Owner::Player) {
        printf(" \033[91m%c\033[0m ", ch);
      } else {
        printf(" \033[94m%c\033[0m ", ch);
      }

      if (col != BOARD_SIZE - 1) {
        printf("|");
      }
    }

    if (row != BOARD_SIZE - 1) {
      printf("\n---+---+---+---+---+---+---+---");
    }

    printf("\n");
  }
}

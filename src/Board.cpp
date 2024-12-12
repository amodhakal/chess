#include "../include/Board.hpp"

#include <cstdio>

const int COMPUTER_MAIN_ROW = 0;
const int PLAYER_MAIN_ROW = 7;

Board::Board() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      m_Board[row][col] = nullptr;
    }
  }

  for (int col = 0; col < BOARD_SIZE; col++) {
    m_Board[COMPUTER_MAIN_ROW + 1][col] =
        new BoardPiece(Owner::Computer, Rank::Pawn);
    m_Board[PLAYER_MAIN_ROW - 1][col] =
        new BoardPiece(Owner::Player, Rank::Pawn);

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

    m_Board[COMPUTER_MAIN_ROW][col] =
        new BoardPiece(Owner::Computer, chosenRank);
    m_Board[PLAYER_MAIN_ROW][col] = new BoardPiece(Owner::Player, chosenRank);
  }
}

void Board::printBoard() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      BoardPiece *piece = m_Board[row][col];

      if (piece == nullptr) {
        printf("  ");
        continue;
      }

      int idx = 0;
      switch (piece->getRank()) {
      case Rank::Pawn:
        idx = 15;
        break;
      case Rank::Knight:
        idx = 13;
        break;
      case Rank::Bishop:
        idx = 1;
        break;
      case Rank::Rook:
        idx = 17;
        break;
      case Rank::Queen:
        idx = 16;
        break;
      case Rank::King:
        idx = 10;
        break;
      }

      char startingA = piece->getOwner() == Owner::Player ? 'A' : 'a';
      printf(" %c ", startingA + idx);

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

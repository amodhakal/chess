#include "../include/Board.h"

int main()
{
  User player1( "Player1", "94" );
  User player2("Player2", "91");
  Board board( player1, player2);

  while ( true ) {
    board.printBoard();
    board.handleUserInput(player1);
    board.printBoard();
    board.handleUserInput(player2);

    break;
  }

  return 0;
}

#include "../include/Board.h"

int main()
{
  Board board( User( "Player1", "94" ), User( "Player2", "91" ));
  board.printBoard();
  return 0;
}

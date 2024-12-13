#include "../include/Board.hpp"
#include "../include/Utils.hpp"

#include <cstdio>

/**
 * The starting function of the chess program
 * @return 0 if success, other numbers otherwise
 */
int main() {
  Board board;
  board.printBoard();

  // Get the player input
  Movement movement = {0};
  getUserMovementInput(&movement);

  return 0;
}

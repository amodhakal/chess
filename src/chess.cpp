#include "../include/Board.hpp"
#include "../include/Utils.hpp"

#include <cstdio>

/**
 * The starting function of the chess program
 * @return 0 if success, other numbers otherwise
 */
int main() {
  Board board;
  Movement movement = {0};

  while (true) {
    board.printBoard();

    // Handle user input and movement
    int placementResult;
    do {
      getUserMovementInput(&movement);
      placementResult = board.makeOwnerMovement(movement, Owner::Player);
    } while (placementResult != 0);
  }

  return 0;
}

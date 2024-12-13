#pragma once

typedef struct {
  int startX;
  int startY;
  int endX;
  int endY;
} Movement;

/**
 * Add the user input movement to the movement parameter
 * @param movement is where the user movement will be stored
 */
void getUserMovementInput(Movement *movement);

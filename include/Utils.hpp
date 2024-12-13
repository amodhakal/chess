#pragma once

/** Represents a change in position */
typedef struct {
  /** Initial x posiiton */
  int startX;
  /** Initial y position */
  int startY; 
  /** Final x position */
  int endX;
  /** Final y position */
  int endY;
} Movement;

/**
 * Add the user input movement to the movement parameter
 * @param movement is where the user movement will be stored
 */
void getUserMovementInput(Movement *movement);

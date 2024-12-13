#include "../include/Utils.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

void getUserMovementInput(Movement *movement) {
  using namespace std;
  const int MAX_ATTEMPTS = 10;
  for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
    // Get user input
    char result[5];
    printf("Enter your movement with start xy, and final xy in form A6B5: ");
    scanf("%4s", result);

    // Check to make sure the input length is correct
    if (strlen(result) != 4) {
      cerr << "Expected format not received, try again!\n";
      continue;
    }

    // Parse user input
    int startX = result[0] - 'A';
    int startY = result[1] - '1';
    int endX = result[2] - 'A';
    int endY = result[3] - '1';

    // Check each of the input
    if (startX < 0 || startX > 7) {
      cerr << "Expected format not received, first one should be A-H\n";
      continue;
    } else if (startY < 0 || startY > 7) {
      cerr << "Expected format not received, second one should be 1-8\n";
      continue;
    } else if (endX < 0 || endX > 7) {
      cerr << "Expected format not received, third one should be A-H\n";
      continue;
    } else if (endY < 0 || endY > 7) {
      cerr << "Expected format not received, last one should be 1-8\n";
      continue;
    }

    // Add user movement and return if successful
    movement->startX = startX;
    movement->startY = startY;
    movement->endX = endX;
    movement->endY = endY;
    return;
  }

  // If the user gets here, it means they don't understand how input
  // works. Explain it in full detail make sure they know
  cerr << "You can reached the max input attempts. Thus, let me explain\n"
          "1. Your input must be 4 characters long\n"
          "2. The first one must be a capital letter between A and H inclusive\n"
          "3. The second one must be a number between 1 and 8 inclusive\n"
          "4. The third one must be a capital letter between A and H inclusive\n"
          "5. The last one must be a number between 1 and 8 inclusive\n\n"
          "With this, we hope you finally understood how the input works.\n"
          "Now try again. If still ensure, email me and I will help you.\n";

  exit(1);
}

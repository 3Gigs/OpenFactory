#include "game.h"
#include <raylib.h>

#define MAX_BUILDINGS 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

void startGameLoop() {
  SetTargetFPS(60);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Untitled Game");

  // Game loop
  while (!WindowShouldClose()) {
    checkInput();
  }

  CloseWindow();
}
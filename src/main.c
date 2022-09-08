#include <raylib.h>
#include <stdio.h>

int main(void) {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 450;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenFactory");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("You've created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
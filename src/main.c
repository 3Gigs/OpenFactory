#include <raylib.h>
#include <stdio.h>

#define MAX_BUILDINGS 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenFactory");

  Vector2 rectPos_Key = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

  Vector2 ballPos_Mouse = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
  Color ballMouseColor = DARKBLUE;

  // Game loop
  // Game loop
  while (!WindowShouldClose()) {
    // Update
    // Update
    HideCursor();
    if (IsKeyDown(KEY_RIGHT))
      rectPos_Key.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
      rectPos_Key.x -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
      rectPos_Key.y += 2.0f;
    if (IsKeyDown(KEY_UP))
      rectPos_Key.y -= 2.0f;

    ballPos_Mouse = GetMousePosition();
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      ballMouseColor = MAROON;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
      ballMouseColor = LIME;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
      ballMouseColor = DARKBLUE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE))
      ballMouseColor = PURPLE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA))
      ballMouseColor = YELLOW;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD))
      ballMouseColor = ORANGE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK))
      ballMouseColor = BEIGE;

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("You've created your first window!", 190, 200, 20, LIGHTGRAY);
    DrawRectangle(rectPos_Key.x, rectPos_Key.y, 10, 10, MAROON);
    DrawCircle(ballPos_Mouse.x, ballPos_Mouse.y, 4, ballMouseColor);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
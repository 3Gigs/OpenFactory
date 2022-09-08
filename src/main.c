#include <raylib.h>
#include <stdio.h>

int main(void) {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 450;

  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenFactory");

  Vector2 ballPosition_Key = { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2 };

  Vector2 ballPosition_Mouse = { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2 };
  Color ballMouseColor = DARKBLUE;

  while (!WindowShouldClose()) {
    HideCursor();
    // Update
    if (IsKeyDown(KEY_RIGHT)) ballPosition_Key.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition_Key.x -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition_Key.y += 2.0f;
    if (IsKeyDown(KEY_UP)) ballPosition_Key.y -= 2.0f;

    ballPosition_Mouse = GetMousePosition();
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) ballMouseColor = MAROON;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ballMouseColor = LIME;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballMouseColor = DARKBLUE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ballMouseColor = PURPLE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ballMouseColor = YELLOW;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ballMouseColor = ORANGE;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ballMouseColor = BEIGE;

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("You've created your first window!", 190, 200, 20, LIGHTGRAY);
    DrawCircle(ballPosition_Key.x, ballPosition_Key.y, 4, MAROON);
    DrawCircle(ballPosition_Mouse.x, ballPosition_Mouse.y, 4, ballMouseColor);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
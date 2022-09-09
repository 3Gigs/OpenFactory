#include <raylib.h>
#include <stdio.h>

#define MAX_BUILDINGS 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
  SetTargetFPS(60);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Untitled Game");

  Color ballMouseColor = DARKBLUE;
  Vector2 ballPos_Mouse = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

  Rectangle player = { 400, 280, 40, 40 };
  Camera2D p_camera = {0}; // TODO: Work on camera
  p_camera.target = (Vector2){player.x + 20.0f, player.y + 20.0f};
  p_camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  p_camera.rotation = 0.0f;
  p_camera.zoom = 1.0f;

  Rectangle buildings[MAX_BUILDINGS] = {0};
  Color buildColors[MAX_BUILDINGS] = {0};
  int spacing = 0;
  for (int i = 0; i < MAX_BUILDINGS; i++) {
    buildings[i].width = (float)GetRandomValue(50, 200);
    buildings[i].height = (float)GetRandomValue(100, 800);
    buildings[i].y = SCREEN_HEIGHT - 130.0f - buildings[i].height;
    buildings[i].x = -6000.0f + spacing;

    spacing += (int)buildings[i].width;

    buildColors[i] = (Color){GetRandomValue(200, 240), GetRandomValue(200, 240),
                             GetRandomValue(200, 250), 255};
  }

  // Game loop
  while (!WindowShouldClose()) {
    ClearBackground(RAYWHITE);
    // Update
    HideCursor();
    if (IsKeyDown(KEY_RIGHT))
      player.x += 25.0f;
    if (IsKeyDown(KEY_LEFT))
      player.x -= 25.0f;
    if (IsKeyDown(KEY_DOWN))
      player.y += 2.0f;
    if (IsKeyDown(KEY_UP))
      player.y -= 2.0f;
    p_camera.target = (Vector2){player.x + 20, player.y + 20};

    ballPos_Mouse = GetMousePosition();

    // Draw
    BeginDrawing();

    BeginMode2D(p_camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
    for (int i = 0; i < MAX_BUILDINGS; i++)
      DrawRectangleRec(buildings[i], buildColors[i]);
    DrawRectangleRec(player, RED);

    EndMode2D();

    DrawText("SCREEN AREA", 640, 10, 20, RED);

    DrawRectangle(0, 0, SCREEN_WIDTH, 5, RED);
    DrawRectangle(0, 5, 5, SCREEN_HEIGHT - 10, RED);
    DrawRectangle(SCREEN_WIDTH - 5, 5, 5, SCREEN_HEIGHT - 10, RED);
    DrawRectangle(0, SCREEN_HEIGHT - 5, SCREEN_WIDTH, 5, RED);

    DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 250, 113, BLUE);

    DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
    DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
    DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);
    DrawCircle(ballPos_Mouse.x, ballPos_Mouse.y, 4, ballMouseColor);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
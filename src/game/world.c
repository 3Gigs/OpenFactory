#include "game.h"
#include <raylib.h>

#define MAX_COLUMNS 20

static float heights[MAX_COLUMNS] = {0};
static Vector3 positions[MAX_COLUMNS] = {0};
static Color colors[MAX_COLUMNS] = {0};

void initWorld() {
  // Generate random columns
  for (int i = 0; i < MAX_COLUMNS; i++) {
    heights[i] = GetRandomValue(1, 12);
    positions[i] = (Vector3){GetRandomValue(-15, 15), heights[i] / 2.0f,
                             GetRandomValue(-15, 15)};
    colors[i] =
        (Color){GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255};
  }
}

void drawWorld(Player *player) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  BeginMode3D(player->camera);

  DrawPlane((Vector3){0}, (Vector2){32.0f, 32.0f}, LIGHTGRAY);

  EndMode3D();

  EndDrawing();
}
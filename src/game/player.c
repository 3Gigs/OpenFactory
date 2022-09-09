#include "game.h"
#include <raylib.h>

Player* createPlayer() {
    Player* player = &(Player){ 0 };
    player->camera = (Camera){
        .position = (Vector3){ 4.0f, 2.0f, 4.0f },
        .target = (Vector3){ 0.0f, 1.8f, 0.0f },
        .up = (Vector3){ 0.0f, 1.0f, 0.0f },
        .fovy = 70.0f,
        .projection = CAMERA_FIRST_PERSON,
    };

    return player;
}
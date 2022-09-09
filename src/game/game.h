#include <raylib.h>

void checkInput();
void startGameLoop();
typedef struct _Player {
    Camera camera;
} Player;
Player* createPlayer();
void initWorld();
void drawWorld(Player* player);

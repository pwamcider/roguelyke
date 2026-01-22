#include "raylib.h"
#include "setup.h"
#include "ui.h"

// ------------------------------------------------------------

void InitGame(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}
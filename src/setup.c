#include "raylib.h"
#include "setup.h"
#include "ui.h"

// ------------------------------------------------------------

void InitGame(void){
    InitWindow(GameWindow.width, GameWindow.height, GameWindow.title);
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}
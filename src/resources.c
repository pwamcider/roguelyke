#include "resources.h"

// ------------------------------------------------------------

Font gameFont;

void LoadResources(void){
    gameFont = LoadFont("resources/fonts//pixantiqua.png");
}

void UnloadResources(void){
    UnloadFont(gameFont);
}
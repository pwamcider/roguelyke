#pragma once

#include "raylib.h"

// ------------------------------------------------------------

typedef struct Window {
    char title[128];
    int width;
    int height;
} Window;

typedef struct View {
    int cellBuffer;
    Vector2 originPoint;
} View;

// ------------------------------------------------------------

extern Window GameWindow;
extern View GameView;
#pragma once

#include "raylib.h"

// ------------------------------------------------------------

typedef struct Window {
    char title[128];
    int width;
    int height;
} Window;

typedef struct View {
    float cellBuffer;
    Vector2 originPoint;
} View;

typedef struct Text {
    int size;
    int spacing;
} Text;

// ------------------------------------------------------------

extern Text GameText;
extern View GameView;
extern Window GameWindow;
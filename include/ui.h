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

typedef struct Inputs {
    int keyMoveNorth;
    int moveNorth;
    int keyMoveEast;
    int moveEast;
    int keyMoveSouth;
    int moveSouth;
    int keyMoveWest;
    int moveWest;
    int keyWait;
    int wait;
    int noInput;
} Inputs;

// ------------------------------------------------------------

extern Inputs GameInputs;
extern Text GameText;
extern View GameView;
extern Window GameWindow;
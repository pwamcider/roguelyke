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

typedef struct AdventureLogUI {
    float entryHeight;
    Vector2 originPoint;
} AdventureLogUI;

typedef struct Text {
    int size;
    int spacing;
} Text;

typedef struct Inputs {
    int keyMoveNorth;
    int moveNorth;
    int keyMoveNorthEast;
    int moveNorthEast;
    int keyMoveEast;
    int moveEast;
    int keyMoveSouthEast;
    int moveSouthEast;
    int keyMoveSouth;
    int moveSouth;
    int keyMoveSouthWest;
    int moveSouthWest;
    int keyMoveWest;
    int moveWest;
    int keyMoveNorthWest;
    int moveNorthWest;
    int keyWait;
    int wait;
    int noInput;
} Inputs;

// ------------------------------------------------------------

extern AdventureLogUI AdvLogUI;
extern Inputs GameInputs;
extern Text GameText;
extern View GameView;
extern Window GameWindow;
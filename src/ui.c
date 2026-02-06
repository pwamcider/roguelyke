#include "resources.h"
#include "ui.h"

// ------------------------------------------------------------

Window GameWindow = {
    .title = "ROGUELYKE",
    .width = 1280,
    .height = 720
};

View GameView = {
    .cellBuffer = 20.0,
    .originPoint = { 50.0f, 50.0f },
};

Text GameText = {
    .size = 20,
    .spacing = 5,
};

Inputs GameInputs = {
    .keyMoveNorth = KEY_KP_8,
    .moveNorth = 8,
    .keyMoveEast = KEY_KP_6,
    .moveEast = 6,
    .keyMoveSouth = KEY_KP_2,
    .moveSouth = 2,
    .keyMoveWest = KEY_KP_4,
    .moveWest = 4,
    .keyWait = KEY_KP_5,
    .wait = 5,
    .noInput = 0,
};
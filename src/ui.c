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

AdventureLogUI AdvLogUI = {
    .entryHeight = 30.0,
    .originPoint = {700.0f, 50.0f},
};

Text GameText = {
    .size = 20,
    .spacing = 5,
};

Inputs GameInputs = {
    .keyMoveNorth = KEY_KP_8,
    .moveNorth = 8,
    .keyMoveNorthEast = KEY_KP_9,
    .moveNorthEast = 9,
    .keyMoveEast = KEY_KP_6,
    .moveEast = 6,
    .keyMoveSouthEast = KEY_KP_3,
    .moveSouthEast = 3,
    .keyMoveSouth = KEY_KP_2,
    .moveSouth = 2,
    .keyMoveSouthWest = KEY_KP_1,
    .moveSouthWest = 1,
    .keyMoveWest = KEY_KP_4,
    .moveWest = 4,
    .keyMoveNorthWest = KEY_KP_7,
    .moveNorthWest = 7,
    .keyWait = KEY_KP_5,
    .wait = 5,
    .noInput = 0,
};
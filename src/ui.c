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
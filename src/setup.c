#include "creatures.h"
#include "generation.h"
#include "raylib.h"
#include "setup.h"
#include "ui.h"
#include "update.h"
#include "world.h"

// TODO - TEMP
#include "advlog.h"
#include "pathfinding.h"

// ------------------------------------------------------------

void InitGame(void) {
    InitWindow(GameWindow.width, GameWindow.height, GameWindow.title);
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

}

// TODO - Temp
void RunTests(void) {
    FieldLoc testingLoc = {
		.x = 15,
		.y = 15,
	};
	CheckNearbyCells(testingLoc);

    FieldLoc start = {
        .x = 0,
        .y = 0,
    };
    FieldLoc end = {
        .x = 16,
        .y = 3,
    };

    FieldLoc path[fieldSizeX * fieldSizeY];

    int pathSize = FindPath(start, end, path, sizeof(path));
}

void SetupGameState(void) {
    AssignGameSeed();

    SetRandomSeed(GameSeed);

    SetupAdvLog();

	ClearWorld();

	GenerateGrass();

    PopHeroRandom();

    PopOakTrees();

    // TODO - Temp
    RunTests();
}

void ShutdownGame(void) {
    CloseAudioDevice();
    CloseWindow();
}
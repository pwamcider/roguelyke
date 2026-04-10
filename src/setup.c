#include "creatures.h"
#include "generation.h"
#include "raylib.h"
#include "setup.h"
#include "ui.h"
#include "update.h"
#include "world.h"

// TODO - TEMP
#include "advlog.h"

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
}

void SetupGameState(void) {
    AssignGameSeed();

    SetRandomSeed(GameSeed);

    ClearAdvLog();

    // TODO - TEMP
    UpdateAdvLog("Welcome to Roguelyke!");

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
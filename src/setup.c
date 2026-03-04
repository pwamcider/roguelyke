#include "creatures.h"
#include "generation.h"
#include "raylib.h"
#include "setup.h"
#include "ui.h"
#include "update.h"
#include "world.h"

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

	World.cells[2][2].entity = &OakTree;

	CheckNearbyCells(testingLoc);
}

void SetupGameState(void) {
    AssignGameSeed();

    SetRandomSeed(GameSeed);

	ClearWorld();

	GenerateGrass();

	PlacePlayerRandom();

    // TODO - Temp
    RunTests();
}

void ShutdownGame(void) {
    CloseAudioDevice();
    CloseWindow();
}
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
        .x = 5,
        .y = 5,
    };

    FieldLoc path[fieldSizeX * fieldSizeY];

    int pathSize = FindPath(start, end, path, sizeof(path));

    for (int i = 0; i < pathSize; i++)
    {
        printf("Loc x = %i, Loc y = %i \n", path[i].x, path[i].y);
    }

    FieldLoc trialA = {
        .x = 17,
        .y = 18,
    };

    FieldLoc trialB;

    trialB = trialA;

    printf("TrialB x = %i, TrialB y = %i\n", trialB.x, trialB.y);

    if ((trialA.x == trialB.x) && (trialA.y == trialB.y))
    {
        printf("Success! They the same!\n");
    }
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
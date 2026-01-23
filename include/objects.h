#pragma once

// ------------------------------------------------------------

#define fieldSizeX 50
#define fieldSizeY 50

typedef struct Field
{
	// Needs to be placed on the screen.
	// Needs container to hold values so draw function knows what to write
	char* cells[fieldSizeX][fieldSizeY];
} Field;
#pragma once

#include "raylib.h"

// ------------------------------------------------------------

#define fieldSizeX 30
#define fieldSizeY 30

// Game Entity Types
// ------------------------------------------------------------

typedef enum EntityType {
	HERO,
	MONSTER,
	ITEM,
	INANIMATE,
} EntityType;

// Hero Struct
// ------------------------------------------------------------

typedef struct Hero {
	// Attributes

	// Visual
	const char* icon;
	Color color;
} Hero;

// Game Structs
// ------------------------------------------------------------

typedef struct Monster {
	// TODO
} Monster;

typedef struct Item {
	// TODO
} Item;

typedef struct Inanimate {
	// TODO
} Inanimate;

typedef struct Entity {
	union {
		Hero hero;
		Monster monster;
		Item item;
		Inanimate inanimate;
	} data;
	EntityType type;
} Entity;

// Walkable
// ------------------------------------------------------------

typedef enum GroundType {
	GRASS,
	SOIL,
} GroundType;

typedef struct GroundVisuals {
	Color grassColor;
	Color soilColor;
	const char* grassIcon;
	const char* soilIcon;
} GroundVisuals;

// World Structs
// ------------------------------------------------------------

typedef struct Cell {
	GroundType type;
	Entity* entity;
} Cell;

typedef struct Field {
	Cell cells[fieldSizeX][fieldSizeY];
	// Using pointers allows something to be NULL. If it might be NULL sometimes, use a pointer.
} Field;

typedef struct FieldLoc
{
	int x;
	int y;
} FieldLoc;

// Declarations
// ------------------------------------------------------------

extern Entity PlayerHero;
extern Field World;
extern GroundVisuals Ground;

// ------------------------------------------------------------

// Sample function using prior example.
/*
int GetHealth(Entity* entity) {
	if (entity->type == GOBLIN)
	{
		
	}
	
};
*/

// TODO - consider a ReturnIcon function where all the char icons live in one place; using a switch.
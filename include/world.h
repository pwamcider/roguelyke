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
	// Attributes
	
	// Visual
	const char* icon;
	Color color;
} Inanimate;

// TODO - move icon and color into entity struct
// all entities will have these, so no need to repeat across different types.

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
	GroundType groundType;
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
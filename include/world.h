#pragma once

#include "raylib.h"

// ------------------------------------------------------------

#define fieldSizeX 30
#define fieldSizeY 30

// Game Entity Types
// ------------------------------------------------------------

typedef enum EntityType {
	HERO,
	CREATURE,
	ITEM,
	INANIMATE,
} EntityType;

// Hero Struct
// ------------------------------------------------------------

typedef struct Hero {
	// Attributes
	int health;
	int strength;
	int dex;
} Hero;

// Game Structs
// ------------------------------------------------------------

typedef struct Creature {
	// Attributes
	int health;
	int dodge;
} Creature;

typedef struct Item {
	// TODO
} Item;

typedef struct Inanimate {
	// TODO
} Inanimate;

typedef struct Entity {
	union {
		Hero hero;
		Creature creature;
		Item item;
		Inanimate inanimate;
	} data;
	EntityType type;

	// Player-facing Name
	const char* logName;

	// Visuals
	const char* icon;
	Color color;
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

extern Field World;
extern GroundVisuals Ground;

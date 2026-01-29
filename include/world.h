#pragma once

// ------------------------------------------------------------

#define fieldSizeX 50
#define fieldSizeY 50

//
// ------------------------------------------------------------

typedef enum EntityType {
	HERO,
	MONSTER,
	ITEM,
	INANIMATE,
} EntityType;

typedef struct Hero {
	// TODO
} Hero;

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
	// TODO - Consider removal of below char*; relocate to a draw function.
	const char* icon;
	union {
		Hero hero;
		Monster monster;
		Item item;
		Inanimate inanimate;
	} data;
	EntityType type;
} Entity;

typedef enum CellType {
	GROUND,
} CellType;

typedef struct Cell {
	CellType cellType;
	Entity* entity;
} Cell;

typedef struct Field {
	Cell cells[fieldSizeX][fieldSizeY];
	// Using pointers allows something to be NULL. If it might be NULL sometimes, use a pointer.
} Field;

// ------------------------------------------------------------

extern Field GameField;

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
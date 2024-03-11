#pragma once
#include "Room.h"
#include <vector>

enum Direction {UP, DOWN, LEFT, RIGHT};
enum Size {SMALL = 20, MEDIUM = 30, LARGE = 40};

class Labyrinth 
{
public:
	Labyrinth* getInstance();

	Room* generateLabyrinth(Size size);
	Room* getRoom(Room* r, Direction d);

private:
	Labyrinth(){};

	Labyrinth* instance = NULL;
	std::vector<std::vector<Room*>> m_map;
};
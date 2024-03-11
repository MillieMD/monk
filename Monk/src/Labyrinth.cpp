#pragma once
#include "Labyrinth.h"

Labyrinth::Labyrinth()
{

}

Labyrinth* Labyrinth::getInstance()
{
	if (instancePtr == NULL)
	{
		instancePtr = Labyrinth();
	}

	return instancePtr;
}

Room* Labyrinth::generateLabyrinth(Size size)
{
	// Size of map length/width
	int width = ;

	// Imperfect randomisation
	int x = rand() * width;
	int y = rand() * width;

	std::vector<Coord> potentialRooms;

	Room* startRoom = new Room(Coord(x, y), true);
	m_map[x][y] = startRoom;

	for (int i = 1; i < size; i++)
	{

		// Push back adjacent squares, that don't have a room attatched
		if (x > 0 && x < width)
		{
			if (m_map[x][y - 1] == NULL)
			{
				potentialRooms.push_back(Coord(x, y - 1));
			}

			if (m_map[x][y + 1] == NULL)
			{
				potentialRooms.push_back(Coord(x, y + 1));
			}
		}

		if (y > 0 && y < width)
		{
			if (m_map[x-1][y] == NULL)
			{
				potentialRooms.push_back(Coord(x - 1, y));
			}

			if (m_map[x + 1][y] == NULL)
			{
				potentialRooms.push_back(Coord(x + 1, y));
			}
		}

		// Create new Room object
		Room* e = new Room();

		// Select random adjacentRoom
		int randomCoord = rand() * potentialRooms.size();
		Coord a = potentialRooms(randomCoord);

		x = a.x;
		y = a.y;

		m_map[x][y] = e;

		// Last room is always the goal, 
		// as this guarantees the end is on the edge of the map.
		// Prevents rooms from being beyond the goal + unreachable
		if (i == size - 1)
		{
			e->addEvent(END);
		}

	}

	return startRoom;
}

Room* Labyrinth::getRoom(Room* r, Direction d)
{

	Room* nextRoom = NULL;

	switch (d)
	{
		case(UP)
		{
			x = r->getCoords().x;
			y = r->getCoords().y + 1;
			break;
		}

		case(DOWN)
		{
			x = r->getCoords().x;
			y = r->getCoords().y - 1;
			break;
		}

		case(LEFT)
		{
			x = r->getCoords().x-1;
			y = r->getCoords().y;
			break;
		}

		case(RIGHT)
		{
			x = r->getCoords().x+1;
			y = r->getCoords().y;
			break;
		}
	}

	nextRoom = m_map[x][y];
}
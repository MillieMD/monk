#include "Room.h"

Room::Room(const Coord coords, bool startRoom)
{
	m_coords = coords;
}

Coord Room::getCoords()
{
	return m_coords;
}
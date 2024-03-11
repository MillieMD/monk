#pragma once
#include "Monk.h"

struct Coord
{
	int x;
	int y;
};

class Room
{
public:
	Room(Coord coords, bool startRoom = false);

	std::vector<Events::Event*> getEvents();
	void addEvent(EventType e);
	bool isVisited();
	void setVisited(bool visited);

private:
	bool visited = false;
	Coord coords;
	std::vector<Events::Event*> m_events;
};
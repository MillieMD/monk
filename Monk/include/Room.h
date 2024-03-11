#pragma once
#include "Event.h"

#include <string>
#include <vector>

struct Coord
{
	int x;
	int y;
};

struct Item
{
	std::string name;
	std::string desc;

	int score;
};

class Room
{
public:
	Room(const Coord coords, bool startRoom = false);

	std::vector<Events::Event*> getEvents();
	void addEvent(Events::EventType e);

	bool isVisited();
	void setVisited(bool visited);
	Coord getCoords();

private:
	bool m_visited = false;
	Coord m_coords;
	std::vector<Events::Event*> m_events;
};
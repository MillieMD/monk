#include "Room.h"

Room::Room(const Coord coords, bool startRoom)
{
	m_coords = coords;
	
	if (startRoom)
	{
		m_visited = true;
		return;
	}

	// Randomly add new events to new room
	while (rand()%10 > 9)
	{

		if (rand()%1 > 5)
		{
			m_events.push_back(new CombatEvent());
		}
		else
		{
			m_events.push_back(new LootEvent());
		}

	}
}

void Room::addEvent(Events::EventType e)
{
	switch (e)
	{
		case(Events::END):
			m_events.push_back(new Events::EndEvent());
			break;

		case(Events::COMBAT):
			m_events.push_back(new Events::CombatEvent());
			break;
		
		case(Events::LOOT):
			m_events.push_back(new Events::LootEvent());
			break;

	}
}

void Room::setVisited(bool visited)
{
	m_visited = visited;
}

bool Room::isVisited()
{
	return m_visited;
}

std::vector<Events::Event*> Room::getEvents()
{
	return m_events;
}

Coord Room::getCoords()
{
	return m_coords;
}
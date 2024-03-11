#pragma once
#include "Event.h"

#include "Event.h"
#include "Goblin.h"

namespace Events {

	Event::Event(EventType e)
	{
		m_priority = e;
	}

	// Used for sorting
	int Event::getPriority()
	{
		return m_priority;
	}


	EndEvent::EndEvent() : Event(END) {}

	void EndEvent::run(Player* p)
	{
		// Game ends : Player wins
	}


	CombatEvent::CombatEvent() : Event(COMBAT)
	{
		// Choose random enemy (when more enemies are added)
		m_enemy = new Goblin();
	}

	void CombatEvent::run(Player* p)
	{

		while (p->getHealth() > 0)
		{

			p->takeTurn(m_enemy);

			if (m_enemy->getHealth() < 0)
			{
				// Player wins
				return;
			}

			m_enemy->takeTurn(p);

		}

		// Player loses : game over

	}


	LootEvent::LootEvent() : Event(LOOT)
	{
		Item loot;
		loot.name = "Loot";
		loot.desc = "Shiny!!";
		loot.score = 10;

		m_loot = loot;
	}

	void LootEvent::run(Player* p)
	{
		p->pickUpItem(m_loot);
	}

}

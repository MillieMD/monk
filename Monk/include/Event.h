#pragma once
#include "Player.h"
#include "Combatant.h"

namespace Events
{
	// Combat > End > Loot
	enum EventType {LOOT, END, COMBAT};

	class Event
	{
	public:
		Event(EventType e);

		virtual void run(Player* p)=0;
		EventType getPriority();
	private:
		EventType m_priority;
	};

	class EndEvent : public Event
	{
	public:
		EndEvent();
		void run(Player* p) override;
	};

	class CombatEvent : public Event
	{
	public:
		CombatEvent();
		void run(Player* p) override;
	private:
		Combatant* m_enemy;
	};

	class LootEvent : public Event
	{
	public:
		LootEvent();
		void run(Player* p) override;
	private:
		Item m_loot;
	};

}
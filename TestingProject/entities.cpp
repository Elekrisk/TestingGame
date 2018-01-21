#include "stdafx.h"

#include "entities.h"

Entity::Entity(const std::string &name)
{
	m_name = name;
	setUnusedId();
	setAttribute(SPECIAL, 10);
	setAttribute(STRENGTH, 5);
	setAttribute(DEXTERITY, 5);
}

Entity::Entity(const std::string &name, int hp, Entity::Allegiance allegiance) : Entity(name)
{
	m_hp = hp;
	m_maxHp = hp;
}

Entity::Entity(const std::string &name, int hp, int maxHp, Entity::Allegiance allegiance) : Entity(name, hp, allegiance)
{
	m_maxHp = maxHp;
	m_allegiance = allegiance;
}

void Entity::setUnusedId()
{
	static int ID = 0;
	m_entityId = ID;
	++ID;
}

void Entity::printInfo() const
{
	std::cout << "Entity ID: " << m_entityId << "\n\tEntity name: " << m_name << "\n\tEntity HP: " << m_hp << " / " << m_maxHp <<
		"\n\tEntity allegiance: " << getAllegianceString() << "\n";
}

int Entity::getId() const
{
	return m_entityId;
}

std::string Entity::getAllegianceString() const
{
	switch (m_allegiance)
	{
		case Entity::ALLIED:
			return "allied";
		case Entity::NEUTRAL:
			return "neutral";
		case Entity::HOSTILE:
			return "hostile";
		default:
			return "???";
			break;
	}
}

void Entity::setAttribute(Entity::Attribute attr, int value)
{
	switch (value)
	{
		case Entity::HEALTH:
			m_maxHp = value;
			if (m_hp > m_maxHp)
			{
				m_hp = m_maxHp;
			}
			break;
		case Entity::SPECIAL:
			m_maxSp = value;
			if (m_sp > m_maxSp)
			{
				m_sp = m_maxSp;
			}
			break;
		case Entity::STRENGTH:
			m_str = value;
			break;
		case Entity::DEXTERITY:
			m_dex = value;
			break;
		default:
			break;
	}
}

int Entity::getCurrentRoomIndex() const
{
	return m_currentRoom;
}

int Entity::setCurrentRoomIndex(int roomIndex)
{
	m_currentRoom = roomIndex;
}

/// PLAYER CLASS

Player::Player(int hp) : Entity("Player", hp, ALLIED)
{
	setAttribute(SPECIAL, 10);
	setAttribute(STRENGTH, 5);
	setAttribute(DEXTERITY, 5);
}

bool Player::pickUpItem()
{
	
}
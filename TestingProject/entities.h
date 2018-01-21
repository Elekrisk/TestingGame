#pragma once

#include "items.h"
#include "map.h"

#include <iostream>
#include <string>

class Entity
{
public:
	enum Allegiance
	{
		ALLIED,
		NEUTRAL,
		HOSTILE
	};

	enum Attribute
	{
		HEALTH,
		SPECIAL,
		STRENGTH,
		DEXTERITY
	};

private:
	int m_currentRoom{ -1 };

	std::string m_name{ "???" };
	int m_hp{ 1 };
	int m_maxHp{ 1 };
	int m_sp{ 1 };
	int m_maxSp{ 1 };
	Allegiance m_allegiance{ NEUTRAL};
	int m_entityId{ -1 };

	void setUnusedId();

	int m_str{ 1 };
	int m_dex{ 1 };



public:
	Entity(const std::string &name);
	Entity(const std::string &name, int hp, int maxHp = -1, Allegiance = NEUTRAL);
	Entity(const std::string &name, int hp, Allegiance allegiance);
	
	void printInfo() const;
	int getId() const;

	std::string getAllegianceString() const;

	void setAttribute(Attribute, int value);
	int getCurrentRoomIndex() const;
	int setCurrentRoomIndex(int roomIndex);
};

class Monster : public Entity
{
	
};

class Player : public Entity
{
private:
	Inventory inventory{ };
	Inventory equipped{ };

public:
	Player(int hp = 25);

	bool pickUpItem();
};
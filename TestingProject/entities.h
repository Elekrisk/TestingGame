#pragma once

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

private:
	std::string m_name{ "???" };
	int m_hp{ 1 };
	int m_maxHp{ 1 };
	Allegiance m_allegiance{ NEUTRAL};
	int m_entityId{ -1 };

	void setUnusedId();

public:
	Entity(const std::string &name);
	Entity(const std::string &name, int hp, int maxHp = -1, Allegiance = NEUTRAL);
	Entity(const std::string &name, int hp, Allegiance allegiance);
	
	void printInfo() const;
	int getId() const;

	std::string getAllegianceString() const;
};

class Player : public Entity
{
public:
	Player(int hp = 25);
};
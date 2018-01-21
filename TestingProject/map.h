#pragma once

#include <vector>


class Door
{
	Room target;
};

class Room
{
	int roomNumber;
	std::vector<Door> doors;
};

class Floor
{
	int floorNumber;

	std::vector<Room> rooms{ };
};

class Map
{
	std::vector<Floor> floors{ };
};
// TestingProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "entities.h"


int main()
{
	Entity e("Example");
	e.printInfo();
	Player player;
	player.printInfo();
	return 0;
}
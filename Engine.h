#pragma once
#include "stdafx.h"
#include "Hero.h"
#include "TileMap.h"
#include "Data.h"

class Engine
{
	sf::RenderWindow m_Window;
	TileMap map;
	Hero m_Hero;
	void input();
	void update(float dtAsSeconds);
	void draw();
	// define the level with an array of tile indices
	const int level[Data::SPRITES_PER_SCREEN] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 0, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

public:
	Engine();
	void start();
};


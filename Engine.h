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
	sf::Text hud;
	sf::Font font;
	void keepAspectRatio();
	void input();
	void update(float dtAsSeconds);
	void draw();
	// define the level with an array of tile indices
	const int level[Data::SPRITES_PER_SCREEN] =
	{
		0,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,
		0,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,
		1,1,1,0,1,1,1,3,3,0,0,0,0,0,0,3,
		0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,2,
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		3,3,0,0,0,0,1,0,0,0,0,0,0,0,2,2,
		3,3,3,3,3,0,1,0,0,0,2,2,2,2,2,2
	};

public:
	Engine();
	void start();
};


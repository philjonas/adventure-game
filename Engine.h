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

public:
	Engine();
	void start();
};


#pragma once
#include "stdafx.h"
#include "Data.h"

class Hero
{
	const static int MAX_FRAME = 1;
	sf::Vector2f m_Position;
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	Facing direction;
	int frame;
	float timer;
	float framerate;
	bool isMoving;
	// Hero's speed in pixels per second
	float m_Speed;
	bool isInBounds(sf::Vector2f pos);
	void setSpriteDirection(float elapsedTime);
public:
	Hero();
	sf::Sprite getSprite();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopMoving();
	void update(float elapsedTime);
	sf::Vector2i getGridPosition();
	sf::Vector2i getNextGridSpace();
	bool checkCollision(sf::Vector2i otherObj);
};
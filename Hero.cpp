#include "Hero.h"

Hero::Hero()
{
	isMoving = false;
	m_Speed = 150;
	framerate = m_Speed / 1000;
	frame =0;
	timer = 0;

	m_Texture.loadFromFile("assets/hero.png");
	direction = south;
	setSpriteDirection(0.0f);
	m_Sprite.setTexture(m_Texture);

	m_Position.x = 0;
	m_Position.y = 0;
}

sf::Sprite Hero::getSprite()
{
	return m_Sprite;
}

void Hero::moveLeft()
{
	direction = west;
	isMoving = true;
}

void Hero::moveRight()
{
	direction = east;
	isMoving = true;
}

void Hero::moveUp()
{
	direction = north;
	isMoving = true;
}

void Hero::moveDown()
{
	direction = south;
	isMoving = true;
}

void Hero::stopMoving()
{
	isMoving = false;
}

void Hero::update(float elapsedTime)
{
	setSpriteDirection(elapsedTime);
	sf::Vector2f prevPosition = m_Position;
	if (isMoving && direction == east)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (isMoving && direction == west)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (isMoving && direction == north)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}

	if (isMoving && direction == south)
	{
		m_Position.y += m_Speed * elapsedTime;
	}

	if (!isInBounds(m_Position)) {
		m_Position = prevPosition;
	}

	m_Sprite.setPosition(m_Position);
}

bool Hero::isInBounds(sf::Vector2f pos) {
	return pos.x >= 0.0f
		&& pos.y >= 0.0f 
		&& pos.x < (float)(Data::WIDTH_IN_PIXELS - Data::SPRITE_SIDE)
		&& pos.y < (float)(Data::HEIGHT_IN_PIXELS - Data::SPRITE_SIDE);
}

void Hero::setSpriteDirection(float elapsedTime) {
	int y = Data::SPRITE_SIDE * (int)direction;
	if (isMoving) {
		timer += elapsedTime;
	}
	// std::cout << timer << std::endl;
	if (timer > framerate) {
		frame++;
		if (frame > MAX_FRAME) {
			frame = 0;
		}
		timer = 0;
	}
	int x = Data::SPRITE_SIDE * frame;
	m_Sprite.setTextureRect(sf::IntRect(x, y, Data::SPRITE_SIDE, Data::SPRITE_SIDE));
}

sf::Vector2i Hero::getGridPosition(){
	return sf::Vector2i(
		m_Position.x / Data::SPRITE_SIDE,
		m_Position.y / Data::SPRITE_SIDE
	);
}

sf::Vector2i Hero::getNextGridSpace(){
	sf::Vector2i currPos = getGridPosition();
	switch (direction)
	{
	case north:
		return sf::Vector2i(currPos.x, currPos.y - 1);
	case south:
		return sf::Vector2i(currPos.x, currPos.y + 1);
	case east:
		return sf::Vector2i(currPos.x + 1, currPos.y);
	case west:
		return sf::Vector2i(currPos.x - 1, currPos.y);
	default:
		return currPos;
	}
}
#include "Engine.h"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	sf::Vector2f resolution;
	resolution.x = Data::SPRITE_SIDE * Data::WIDTH_IN_SPRITES;
	resolution.y = Data::SPRITE_SIDE * Data::HEIGHT_IN_SPRITES;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y),
		"Simple Game Engine",
		sf::Style::Default);

	// define the level with an array of tile indices
	const int level[] =
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
	
	map.load(
		"assets/tileset.png", 
		sf::Vector2u(Data::SPRITE_SIDE, Data::SPRITE_SIDE),
		level, 
		Data::WIDTH_IN_SPRITES,
		Data::HEIGHT_IN_SPRITES
		);

}

void Engine::start()
{
	// Timing
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}
		// Restart the clock and save the elapsed time into dt
		sf::Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}

void Engine::input()
{
	// Handle the player quitting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_Window.close();
	}

	m_Hero.stopMoving();
	// Handle the player moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Hero.moveLeft();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Hero.moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_Hero.moveUp();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_Hero.moveDown();
	}


}

void Engine::update(float dtAsSeconds)
{
	m_Hero.update(dtAsSeconds);
}

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	m_Window.draw(map);
	m_Window.draw(m_Hero.getSprite());

	m_Window.display();
}
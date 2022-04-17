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
			if (event.type == sf::Event::Closed){
				m_Window.close();
			}

			if (event.type == sf::Event::Resized)
			{
				keepAspectRatio();
				// float fontSize = getFontSize(windowHeight);
				// hud.setCharacterSize((unsigned int)fontSize);
			}
				
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
	sf::Vector2i nextGridSpace = m_Hero.getNextGridSpace();
	int nextIndex = nextGridSpace.y * Data::WIDTH_IN_SPRITES + nextGridSpace.x;
	if(nextIndex < 0 || nextIndex > Data::SPRITES_PER_SCREEN - 1){
		return;
	}
	if(level[nextIndex] != 0 && m_Hero.checkCollision(nextGridSpace)){ // it is an obstacle
		m_Hero.stopMoving();
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

void Engine::keepAspectRatio()
{
	// https://stackoverflow.com/questions/63796551/how-to-keep-the-windows-aspect-ratio-while-resizing-the-window-in-sfml-2-5
	sf::Vector2u size = m_Window.getSize();
	// setup my wanted aspect ratio
	float  heightRatio = Data::HEIGHT_IN_PIXELS / (float)Data::WIDTH_IN_PIXELS;
	float  widthRatio = Data::WIDTH_IN_PIXELS / (float)Data::HEIGHT_IN_PIXELS;
	// adapt the resized window to my wanted aspect ratio
	if (size.y * widthRatio <= size.x)
	{
		size.x = size.y * widthRatio;
	}
	else if (size.x * heightRatio <= size.y)
	{
		size.y = size.x * heightRatio;
	}
	// set the new size
	m_Window.setSize(size);
}

float Engine::getFontSize(unsigned int windowHeight)
{
	return ((windowHeight / 200.0f) + 1) * 10;
}
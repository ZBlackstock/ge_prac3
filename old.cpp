/*
#include <SFML/Graphics.hpp>
#include <iostream>

const int gameWidth = 800;
const int gameHeight = 600;
const float time_step = 0.017f;

sf::Texture spritesheet;
sf::Sprite invader;

void reset()
{

}

void init()
{
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
}

void update(float deltaTime)
{

}

void render(sf::RenderWindow& window)
{
	window.draw(invader);
}

int mainfffff()
{
	sf::RenderWindow window(sf::VideoMode({ gameWidth,gameHeight }), "Space_Invaders");
	init();

	while (window.isOpen())
	{
		static sf::Clock clock;
		const float deltaTime = clock.restart().asSeconds();

		window.clear();
		update(deltaTime);
		render(window);
		sf::sleep(sf::seconds(time_step));
		window.display();
	}

	return 0;
}
*/


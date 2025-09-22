#include <SFML/Graphics.hpp>

const int gameWidth = 800;
const int gameHeight = 600;
const float time_step = 0.017f;

sf::Texture spritesheet;
sf::Sprite invader;

const sf::Keyboard::Key controls[4] =
{
};

void reset()
{

}

void init()
{
	
}

void update(float deltaTime)
{

}

void render(sf::RenderWindow& window)
{

}

int main()
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


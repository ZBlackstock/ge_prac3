#include "game_system.hpp"
#include "game_parameters.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

std::vector<std::shared_ptr<Ship>> GameSystem::ships;
int main();

void GameSystem::init() {
	std::shared_ptr<Invader> inv = std::make_shared<Invader>(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)), sf::Vector2f{ 100,100 });
	GameSystem::ships.push_back(inv);
}

void GameSystem::update(const float& dt) {

	for (std::shared_ptr<Ship>& s : GameSystem::ships) {
		s->Update(dt);
	}
}

void GameSystem::render(sf::RenderWindow& window) {

	for (const std::shared_ptr<Ship>& s : GameSystem::ships) {
		window.draw(*(s.get()));
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode({ Parameters::game_width, Parameters::game_height }), "Space_Invaders");
	GameSystem::init();

	while (window.isOpen())
	{
		static sf::Clock clock;
		const float deltaTime = clock.restart().asSeconds();

		window.clear();
		GameSystem::update(deltaTime);
		GameSystem::render(window);
		sf::sleep(sf::seconds(Parameters::time_step));
		window.display();
	}

	return 0;
}
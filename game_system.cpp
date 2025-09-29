#include "game_system.hpp"
#include "game_parameters.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

std::vector<std::shared_ptr<Ship>> GameSystem::ships;
Player GameSystem::player;
float GameSystem::playerDirection;
float GameSystem::playerSpeed = 60;
using param = Parameters;

const sf::Keyboard::Key param::controls[3] = {
	sf::Keyboard::Left,
	sf::Keyboard::Right,
	sf::Keyboard::Space
};

int main();

void GameSystem::init() {

	reset();
}

void GameSystem::reset() {
	Invader::speed = 20.f;

	sf::Vector2f position = { 100,100 };

	for (int i = 0; i < 44; i++) {

		if (i % 11 == 0) {
			position.y -= 20;
			position.x = 100;
		}
		position.x += 20;

		std::shared_ptr<Invader> inv = std::make_shared<Invader>(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)), position);
		GameSystem::ships.push_back(inv);
	}

	GameSystem::player = Player();
}

void GameSystem::update(const float& dt) {

	for (std::shared_ptr<Ship>& s : GameSystem::ships) {
		s->Update(dt);
	}

	playerDirection = 0;

	if (sf::Keyboard::isKeyPressed(param::controls[0]))
	{
		playerDirection--;
	}
	if (sf::Keyboard::isKeyPressed(param::controls[1]))
	{
		playerDirection++;
	}

	player.move(playerDirection * GameSystem::playerSpeed * dt, 0.0f);
}

void GameSystem::render(sf::RenderWindow& window) {

	for (const std::shared_ptr<Ship>& s : GameSystem::ships) {
		window.draw(*(s.get()));
	}

	window.draw(player);
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

void GameSystem::clean() {
	for (std::shared_ptr<Ship>& ship : ships) {
		ship.reset();
		ships.clear();
	}
}
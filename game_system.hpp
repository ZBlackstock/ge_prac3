#include <vector>
#include <memory>
#include "ship.hpp"

struct GameSystem {
	//Global variables:
	static std::vector<std::shared_ptr<Ship>> ships;

	//Game System Functions:
	static void init();
	//static void clean();
	static void update(const float& dt);
	static void render(sf::RenderWindow& window);
};
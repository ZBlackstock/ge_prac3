#include <vector>
#include <memory>
#include "ship.hpp"

struct GameSystem {
	//Global variables:
	static std::vector<std::shared_ptr<Ship>> ships;
	static Player player;
	static float playerSpeed;
	static float playerDirection;

	//Game System Functions:
	static void init();
	static void reset();
	static void clean();
	static void update(const float& dt);
	static void render(sf::RenderWindow& window);
};
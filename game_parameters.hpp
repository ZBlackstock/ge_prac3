#pragma once
// Ensure header file is called once

struct Parameters {
public:
	static const sf::Keyboard::Key controls[3];

	static constexpr int game_width = 400;
	static constexpr int game_height = 300;
	static constexpr int sprite_size = 32;
	static constexpr float time_step = 0.017f;
};


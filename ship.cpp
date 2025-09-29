#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"
#include <iostream>

using param = Parameters;
using gs = GameSystem; //renaming GameSystem header file to something more compact;

Ship::Ship() {};



bool Invader::faceRight;
float Invader::speed;

Ship::Ship(const Ship& s) :
	_sprite(s._sprite) {
}

Ship::Ship(sf::IntRect ir) : Sprite() {

	// Load sprite from spritesheet
	_sprite = ir;
	spritesheet.loadFromFile("invaders_sheet.png");
	setTexture(spritesheet);
	setTextureRect(_sprite);
}

void Ship::move_down() {
	setPosition(getPosition().x, getPosition().y + 20);
}

void Ship::Update(const float& dt) {}

Ship::~Ship() = default;

Invader::Invader() : Ship() {}
Invader::Invader(const Invader& inv) : Ship(inv) {}
Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(sf::Vector2f(16.f, 16.f));
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);

	move(dt * (faceRight ? 1.0f : -1.0f) * speed, 0.0f);

	if (faceRight && getPosition().x > param::game_width - param::sprite_size / 2.f ||
		!faceRight && getPosition().x < param::sprite_size / 2.f) {
		faceRight = !faceRight;
		speed += 10;

		for (std::shared_ptr<Ship>& ship : gs::ships) {
			ship->move_down();
		}
	}
}

Player::Player() : Ship(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)))
{
	setOrigin(param::sprite_size / 2.f, param::sprite_size / 2.f);
	setPosition(param::game_width / 2.f, param::game_height - static_cast<float>(param::sprite_size));

	spritesheet.loadFromFile("invaders_sheet.png");
	setTexture(spritesheet);
	setTextureRect(_sprite);
}

void Player::Update(const float& dt) {
	Ship::Update(dt);


}


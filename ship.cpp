#include "ship.hpp"

Ship::Ship() {};

Ship::Ship(const Ship &s) : 
	_sprite(s._sprite) {}

Ship::Ship(sf::IntRect ir) : Sprite() {

	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
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
}
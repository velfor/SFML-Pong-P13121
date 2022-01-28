#pragma once
#include "SFML/Graphics.hpp"

class Ball {
private:
	sf::CircleShape circle;
	sf::FloatRect hitbox;
	float radius = 20.f;
	float speedx = 2.5f;
	float speedy = -2.5f;
public:
	Ball();
	sf::CircleShape getShape();
	sf::Vector2f getPosition();
	void update();
	sf::FloatRect getHitBox();
	void reboundHorizontal();
	void reboundVertical();
};

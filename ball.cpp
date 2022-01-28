#include "ball.h"
#include "const.h"

Ball::Ball() {
	circle.setRadius(radius);
	circle.setPosition(SCREEN_WIDTH/2 - radius, SCREEN_HEIGHT/2 - radius);
	circle.setFillColor(sf::Color::Yellow);
}
sf::CircleShape Ball::getShape() { return circle; }
void Ball::reboundHorizontal() { speedx = -speedx; }
void Ball::reboundVertical() { speedy = -speedy; }
sf::Vector2f Ball::getPosition() { return circle.getPosition(); }
sf::FloatRect Ball::getHitBox() { return circle.getGlobalBounds(); }
size_t Ball::getLeftScore() { return left_score; }
size_t Ball::getRightScore() { return right_score; }
void Ball::update() {
	//движение м€ча
	circle.move(speedx,speedy);
	//если м€ч ударилс€ об левую границу экрана
	if (getPosition().x <= 0){
		speedx = -speedx;
		right_score++;
	}
	//если м€ч ударилс€ об правую границу экрана
	if (getPosition().x + 2 * radius >= SCREEN_WIDTH) {
		speedx = -speedx;
		left_score++;
	}
	if (getPosition().y <= 0 || getPosition().y + 2 * radius >= SCREEN_HEIGHT){
		speedy = -speedy;
	}
}
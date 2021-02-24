#include "Player.h"

Player::Player()
{
	texture.loadFromFile("textures/player.png");
	shape.setTexture(&texture);
	shape.setPosition(375, 500);
	shape.setSize(Vector2f(50, 30));
	bullet.setSize(Vector2f(2, 50));
}

void Player::p_move(float dt)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && shape.getPosition().x >= 0) shape.move(-150 * dt, 0);
	if (Keyboard::isKeyPressed(Keyboard::D) && shape.getPosition().x <= 800 - shape.getSize().x) shape.move(150 * dt, 0);
	if (shoot == false) {
		bullet.setPosition(0, 0);
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			shoot = true;
			bullet.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y - 20);
		}
	}

	if (shoot == true)
	{
		bullet.move(Vector2f(0, -500 * dt));
		if (bullet.getPosition().y < -50) shoot = false;
	}
}

void Player::draw(RenderTarget& target, RenderStates state) const
{
	if(shoot == true) target.draw(bullet);
	target.draw(shape);
}

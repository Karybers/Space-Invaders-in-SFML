#include "Enemy.h"

Enemy::Enemy()
{
	pop_texture.loadFromFile("textures/pop.png");
	texture.loadFromFile("textures/enemy.png");
	shape.setTexture(&texture);
	shape.setSize(Vector2f(50, 30));
	bullet.setSize(Vector2f(2, 30));
	bullet.setFillColor(Color::Red);
}

void Enemy::fire()
{
	bullet.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + (shape.getSize().y * 0.7));
	vec_bullets.push_back(bullet);
}

void Enemy::animate(int frame)
{
	shape.setTexture(&pop_texture);
	shape.setTextureRect(IntRect(frame * 26, 0, 26, 18));
}

void Enemy::update(float dt)
{
	for (int i = 0; i < vec_bullets.size(); i++)
	{
		vec_bullets[i].move(0, 250 * dt);
		if (vec_bullets[i].getPosition().y > 650) vec_bullets.erase(vec_bullets.begin() + i);
	}
}

void Enemy::draw(RenderTarget& target, RenderStates state) const
{
	if(dead == false) target.draw(shape, state);
	for (int i = 0; i < vec_bullets.size(); i++) target.draw(vec_bullets[i], state);
}
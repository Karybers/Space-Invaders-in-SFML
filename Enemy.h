#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
	Texture texture, pop_texture;
	RectangleShape bullet;
	std::vector<RectangleShape> vec_bullets;

	void draw(RenderTarget& target, RenderStates state) const;
public:
	bool dead = false;
	Enemy();
	void animate(int frame);
	void fire();
	void update(float dt);
};


#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	void draw(RenderTarget& target, RenderStates state) const;
public:
	Player();
	void p_move(float dt);
	RectangleShape bullet;
	bool shoot = false;
};


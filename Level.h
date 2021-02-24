#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include "Shield.h"

using namespace sf;

class Level : public Drawable
{
	Player player;
	Enemy enemy;
	Font font;
	Shield shield[4];
	Text continue_text;
	std::vector <Enemy> vec_enemy;
	int lvl = 1;
	int anime_frame = 0;
	bool attack = false;
	int id_att;

	float dt_sum = 0;
	float dt_req = 0;

	void complete();
	void draw(RenderTarget& target, RenderStates state) const;
public:
	void init();
	void update(float dt);
};


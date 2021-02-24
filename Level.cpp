#include "Level.h"

void Level::init()
{
	dt_req = 1;

	for (int i = 0; i < 4; i++) shield[i].create(i * 150 + 150);

	if (lvl == 1){
		font.loadFromFile("consola.ttf");
		continue_text.setCharacterSize(40);
		continue_text.setPosition(55, 100);
		continue_text.setFont(font);
		continue_text.setString("Nacisnij spacje aby kontynuowac");
		for (int i = 0; i < 10; i++)
		{
			vec_enemy.push_back(enemy);
			vec_enemy.back().shape.setPosition(i * (10 + vec_enemy.back().shape.getSize().x) + 100, 50);
		}
	}
	if (lvl == 2){
		for (int i = 0; i < 10; i++) {
			vec_enemy.push_back(enemy);
			vec_enemy.back().shape.setPosition(i * (10 + vec_enemy.back().shape.getSize().x) + 100, 50);
		}
		for (int i = 0; i < 5; i++){ 
			vec_enemy.push_back(enemy);
			vec_enemy.back().shape.setPosition(i * (10 + vec_enemy.back().shape.getSize().x) + 250, 100);
		}
	}
	if (lvl == 3) {
		for (int i = 0; i < 10; i++) {
			vec_enemy.push_back(enemy);
			vec_enemy.back().shape.setPosition(i * (10 + vec_enemy.back().shape.getSize().x) + 100, 50);
		}
		for (int i = 0; i < 10; i++) {
			vec_enemy.push_back(enemy);
			vec_enemy.back().shape.setPosition(i * (10 + vec_enemy.back().shape.getSize().x) + 100, 100);
		}
	}
	if (lvl == 4) {
		continue_text.setString("Wygrana!");
	}
}

void Level::complete()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		lvl++;
		init();
	}
}

void Level::update(float dt) // checks if enemy got shoot
{
	if (vec_enemy.empty()) complete();
	player.p_move(dt);
	dt_sum += dt;
	for (int i = 0; i < vec_enemy.size(); i++) {
		vec_enemy[i].update(dt);
		if (dt_sum > dt_req)
		{
			vec_enemy[rand() % vec_enemy.size()].fire();
			dt_sum = 0;
		}
		if (vec_enemy[i].shape.getGlobalBounds().intersects(player.bullet.getGlobalBounds()))
		{
			if(dt_req > 0.5)dt_req -= 0.2;
			player.shoot = false;
			attack = true;
			id_att = i;
		}
	}
	if (attack == true) {
		vec_enemy[id_att].animate(anime_frame);
		anime_frame++;
		if (anime_frame == 5) {
			anime_frame = 0;
			attack = false;
			vec_enemy.erase(vec_enemy.begin() + id_att);
		}
	}
}

void Level::draw(RenderTarget& target, RenderStates state) const
{
	if (vec_enemy.empty())
	{
		target.draw(continue_text);
	}
	else
	{
		target.draw(player);
		for (int i = 0; i < 4; i++) target.draw(shield[i], state);
		for (int i = 0; i < vec_enemy.size(); i++)
		{
			target.draw(vec_enemy[i], state);
		}
	}
}

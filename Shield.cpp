#include "Shield.h"

void Shield::create(int x)
{
	texture.loadFromFile("textures/shield.png");
	for (int i = 0; i < 6; i++)
	{
		vec_shields.push_back(shld);
		rect[i].width = 15;
		rect[i].height = 14;
		rect[i].top = 0;
		vec_shields[i].setTexture(&texture);
		if (i == 0 || i == 1) {
			rect[i].left = 0;
			vec_shields[i].setTextureRect(rect[i]);
		}
		else {
			rect[i].left = (i - 1) * 15;
			vec_shields[i].setTextureRect(rect[i]);
		}

		if (i == 0 || i == 1)
		{
			vec_shields[i].setSize(Vector2f(rec_width, rec_height));
			if (i == 0) vec_shields[i].setPosition(x, y);
			if (i == 1) vec_shields[i].setPosition(x + (rec_width * 3), y);
		}
		if (i == 2 || i == 3)
		{
			vec_shields[i].setSize(Vector2f(rec_width * 2, rec_height * 0.5));
			if (i == 2) vec_shields[i].setPosition(Vector2f(x, y - (rec_height * 0.5)));
			if (i == 3) vec_shields[i].setPosition(Vector2f(x + (rec_width * 2), y - (rec_height * 0.5)));
		}
		if (i == 4 || i == 5)
		{
			vec_shields[i].setSize(Vector2f(rec_width, rec_height * 0.5));
			if (i == 4) vec_shields[i].setPosition(x + (rec_width * 2), y);
			if (i == 5) vec_shields[i].setPosition(x + rec_width, y);
		}
	}
}

void Shield::attacked()
{

}

void Shield::draw(RenderTarget& target, RenderStates state) const
{
	for (int i = 0; i < vec_shields.size(); i++) target.draw(vec_shields[i], state);
}

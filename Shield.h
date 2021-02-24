#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Shield : public Drawable
{
	int y = 400;
	int rec_width = 30;
	int rec_height = 60;

	Texture texture;
	IntRect rect[6];
	RectangleShape shld;
	std::vector <RectangleShape> vec_shields;
	void draw(RenderTarget& target, RenderStates state) const;
public:
	void create(int x);
	void attacked();
};


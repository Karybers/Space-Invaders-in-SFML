#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu : public Drawable
{
	RectangleShape button[2], left;
	Text menu_text[2];
	Texture pic[2];
	RectangleShape spr_pic[2];
	Font font;
	void click();
	void draw(RenderTarget& target, RenderStates state) const;
public:
	Menu();
	bool isMouseOn(RenderWindow &window, int i); //jesli kursor na przycisku - podswietl
};


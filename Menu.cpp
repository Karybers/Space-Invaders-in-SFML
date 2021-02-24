#include "Menu.h"

Menu::Menu()
{
	pic[0].loadFromFile("textures/enemy.png");
	pic[1].loadFromFile("textures/logotxt.png");
	font.loadFromFile("consola.ttf");
	for (int i = 0; i < 2; i++)
	{
		button[i].setSize(Vector2f(170, 60));
		button[i].setPosition(100, i * 100 + 300);
		button[i].setFillColor(Color(100, 100, 100));
		menu_text[i].setCharacterSize(50);
		menu_text[i].setFont(font);
		menu_text[i].setPosition(button[i].getPosition().x + 10, button[i].getPosition().y - 5);
		spr_pic[i].setTexture(&pic[i]);
	}
	menu_text[0].setString("Graj");
	menu_text[1].setString("Wyjdz");
	left.setFillColor(Color(80, 80, 80));
	left.setSize(Vector2f(300, 600));
	spr_pic[0].setSize(Vector2f(350, 300));
	spr_pic[0].setPosition(370, 50);
	spr_pic[1].setSize(Vector2f(460, 40));
	spr_pic[1].setPosition(320, 500);
}

bool Menu::isMouseOn(RenderWindow &window, int i)
{
	if (button[i].getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
	{
		button[i].setFillColor(Color(130, 130, 130));
		return true;
	}
	else
	{
		button[i].setFillColor(Color(100, 100, 100));
		return false;
	}
}

void Menu::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(left, state);
	for (int i = 0; i < 2; i++) {
		target.draw(button[i], state);
		target.draw(menu_text[i], state);
		target.draw(spr_pic[i], state);
	}
}


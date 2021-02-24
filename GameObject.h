#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class GameObject : public Drawable
{
protected:
	virtual void draw(RenderTarget& target, RenderStates state) const = 0;
	Texture texture;
public:
	RectangleShape shape;
};


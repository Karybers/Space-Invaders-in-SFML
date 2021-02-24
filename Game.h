#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Level.h"
#include <stack>
#include <vector>

using namespace sf;

class Game
{
	RenderWindow window;
	enum State_list {exit, main_menu, play};
	std::stack<State_list> st;
	
	void check_events();
	void ingame();
	void render();

	Menu menu;
	Level level;

	Clock clock;
	float dt = 0;
public:
	Game();
	void run();
};


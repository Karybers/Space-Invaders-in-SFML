#include "Game.h"

Game::Game()
	: window(VideoMode(800, 600), "Aliens!")
{
	window.setFramerateLimit(75);
	st.push(main_menu);
	level.init();
}

void Game::ingame()
{
	level.update(dt);
}

void Game::check_events()
{
	dt = clock.restart().asSeconds();
	std::cout << dt;
	system("cls");

	switch (st.top())
	{
	case play:
	{
		ingame();
		break;
	}
	}
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) window.close();
		if(st.top() == main_menu) 
			for (int i = 0; i < 2; i++)
			{
				menu.isMouseOn(window, i);
				if (event.type == Event::MouseButtonReleased && menu.isMouseOn(window, i) == true && event.mouseButton.button == Mouse::Left){
					if (i == 0) st.push(play);
					if (i == 1) window.close();
				}	
			}
	}
}

void Game::render()
{
	window.clear(Color::Black);
	if (st.top() == play)
	{
		window.draw(level);
	}
	if(st.top() == main_menu) window.draw(menu);
	
	window.display();
}

void Game::run()
{
	check_events();
	render();
}
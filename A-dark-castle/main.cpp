#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "menu.h"
#include "view.h"
#include "const.h"
#include "event.h"



using namespace sf;
void DrawGame(RenderWindow& window, StructMenu menu)
{
	DrawMenu(menu, window);
}
void Run_Game(RenderWindow& window)
{

	StructView view;
	StructMenu menu;
	StructEvent key_event;
	SetView(view);
	InitMenu(menu, view.view_ñentre);
	
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		ViewUpdate(view);
		UpdateMenu(menu, key_event);
		DrawGame(window, menu);
		window.display();
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	sf::RenderWindow window(sf::VideoMode(SIZE_WINDOW.x, SIZE_WINDOW.y), "A dark castle");

	Run_Game(window);
	return 0;
}
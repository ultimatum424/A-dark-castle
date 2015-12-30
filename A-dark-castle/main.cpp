#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "menu.h"
#include "view.h"
#include "const.h"
#include "heroes.h"
#include "battle.h"
#include "event.h"



using namespace sf;

void Init(StructAllHeroes& all_heroes, StructAllEnemy& all_enemy, StructMenu& menu, 
	StructBattleImage& battle_image, StructView& view, StructLocalEnemy local_enemy[5])
{
	InitAllEnemy(all_enemy);
	InitHeroes(all_heroes);
	SetView(view);
	InitMenu(menu, view.view_ñentre);
	InitBattleImages(battle_image);
	InitLocalEnemy(all_enemy, local_enemy);
}
void DrawGame(RenderWindow& window, StructMenu menu)
{
	DrawMenu(menu, window);
}

void Run_Game(RenderWindow& window)
{
	//Event event;
	StructView view;
	StructMenu menu;
	
	StructEvent key_event;
	StructAllEnemy all_enemy;
	StructLocalEnemy local_enemy[5];
	StructAllHeroes all_heroes;
	StructBattleImage battle_image;

	Init(all_heroes, all_enemy, menu, battle_image, view, local_enemy);
	/*InitAllEnemy(all_enemy);
	InitHeroes(all_heroes);
	SetView(view);
	InitMenu(menu, view.view_ñentre);
	InitBattleImages(battle_image);
	InitLocalEnemy(all_enemy, local_enemy);*/
	
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		CheckEvent(window, key_event);
		ViewUpdate(view);
		UpdateMenu(menu);
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
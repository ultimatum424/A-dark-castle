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
int stage_game;
void Init(StructAllHeroes& all_heroes, StructAllEnemy& all_enemy, StructMenu& menu, 
	StructBattleParam& battle_param, StructView& view, StructLocalEnemy local_enemy[5],
	int& stage_game)
{
	SetView(view);
	InitMenu(menu, view.view_ñentre);
	InitBattleParam(battle_param);
	InitHeroes(all_heroes);
	InitAllEnemy(all_enemy);
	InitLocalEnemy(all_enemy, local_enemy);
	stage_game = 0;
}
/*void DrawGame(RenderWindow& window,  StructMenu menu, StructBattleParam battle_param, StructAllHeroes& all_heroes, StructEnemy enemy[3])
{
	
	if (stage_game == 0)
		DrawMenu(menu, window);
	if (stage_game == 1)
	{
		DrawBattleImages(battle_param, all_heroes, enemy, window);
		
	}
}*/

void Run_Game(RenderWindow& window)
{
	//Event event;
	StructView view;
	StructMenu menu;

	StructEvent key_event;
	StructAllEnemy all_enemy;
	StructLocalEnemy local_enemy[5];
	StructAllHeroes all_heroes;
	StructBattleParam battle_param;

	Init(all_heroes, all_enemy, menu, battle_param, view, local_enemy, stage_game);
	
	

	SetHerosAndEnemy(all_heroes, local_enemy, view.view_ñentre);
	while (window.isOpen())
	{
		//std::cout << stage_game << "\n";
		window.clear(sf::Color::White);
		//SetHeroes(all_heroes);
		CheckEvent(window, key_event, stage_game);
		ViewUpdate(view);
		if (stage_game == 0)
		{
			UpdateMenu(menu, key_event, stage_game);
			DrawMenu(menu, window);
		}
		if (stage_game == 1)
		{
			
			BattleMod(all_heroes, local_enemy[0].enemy, view.view_ñentre, battle_param, key_event.key_attack, window);
		}		
		//std::cout << stage_game;
		//DrawGame(window, menu, battle_param, all_heroes, local_enemy[5].enemy);
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
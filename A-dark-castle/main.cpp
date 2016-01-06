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
#include "map.h"
#include "inventory.h"


using namespace sf;


int stage_game;
void Init(StructAllHeroes& all_heroes, StructAllEnemy& all_enemy, StructMenu& menu, 
	StructBattleParam& battle_param, StructView& view, StructLocalEnemy local_enemy[ENEMY_COUNT],
	int& stage_game)
{
	SetView(view);
	InitMenu(menu);
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
	StructMap map;
	StructEvent key_event;
	StructAllEnemy all_enemy;
	StructLocalEnemy local_enemy[ENEMY_COUNT];
	StructAllHeroes all_heroes;
	StructBattleParam battle_param;
	StructTime time_animation;
	StructInventory inventory;
	Init(all_heroes, all_enemy, menu, battle_param, view, local_enemy, stage_game);
	InitMap(map);
	SetHerosAndEnemy(all_heroes, local_enemy, view.view_ñentre);
	InitInventory(inventory);
	InitShop(inventory);
	while (window.isOpen())
	{
		time_animation.clock.restart();
		time_animation.time = time_animation.clock.getElapsedTime().asMicroseconds();
		time_animation.time = time_animation.time / 1000;
		//std::cout << stage_game << "\n";
		window.clear(sf::Color::White);
		//SetHeroes(all_heroes);
		CheckEvent(window, key_event, stage_game);
		window.setView(view.camera);
		ViewUpdate(view, time_animation.time, stage_game);
		if (stage_game == 0)
		{
			if ((key_event.key_escape))
				window.close();
			UpdateMenu(menu, key_event, stage_game, view.view_ñentre);
			DrawMenu(menu, window);
			
		}
		if (stage_game == 1)
		{
			UpdeatInventory(inventory, view.view_ñentre);
			ExplorationMod(map, key_event, inventory, stage_game);
			DrawMap(map, view.view_ñentre, window);
			DrawInventory(inventory, window);
		}
		if (stage_game == 2)
		{
			int falq;
			falq = BattleMod(all_heroes, local_enemy[0].enemy, view.view_ñentre, battle_param, key_event, window);
			if (falq == 2)
			{
				stage_game = 1;
				map.hero_pos = map.previous_hero_pos;
				inventory.food.quantity -= 5;
				inventory.relics.quantity -= 2;
			}
		}		
		if (stage_game == 3)
		{
			ShopMode(inventory, key_event, view.view_ñentre, stage_game);
			DrawShop(inventory, window);
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
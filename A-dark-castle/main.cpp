#include "const.h"
using namespace sf;

int stage_game;
void InitGameOver(StructEndGame& end)
{
	end.bad.image.loadFromFile("../images/end/bad-end.png");
	end.bad.texture.loadFromImage(end.bad.image);
	end.bad.sprite.setTexture(end.bad.texture);

	end.good.image.loadFromFile("../images/end/good-end.png");
	end.good.texture.loadFromImage(end.good.image);
	end.good.sprite.setTexture(end.good.texture);
}
int UpeatGameOver(StructEndGame& end, Vector2f view_ñentre, StructEvent event)
{
	end.bad.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	end.good.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	if (event.key_tab)
		return 1;
	else
		return 0;
}
void DrawGameOver(StructEndGame& end, RenderWindow& window, int stage_game)
{
	if (stage_game == -1)
		window.draw(end.bad.sprite);
}
void Init(StructGame& game)
{
	InitSoundEffects(game.sound_effect);
	InitAllInfo(game.info);
	InitCampfire(game.campfire);
	InitGameOver(game.end_game);
	SetView(game.view);
	InitMenu(game.menu);
	InitBattleParam(game.battle_param);
	InitHeroes(game.all_heroes);
	InitAllEnemy(game.all_enemy);
	InitLocalEnemy(game.all_enemy, game.local_enemy);
	InitMap(game.map);
	SetHerosAndEnemy(game.all_heroes, game.local_enemy, game.view.view_ñentre);
	InitInventory(game.inventory);
	InitShop(game.inventory);
	InitSound(game.sound);
	stage_game = 0;
}
void ReInitParam(StructGame& game)
{
	InitCampfire(game.campfire);
	InitGameOver(game.end_game);
	SetView(game.view);
	InitMenu(game.menu);
	InitBattleParam(game.battle_param);
	InitHeroes(game.all_heroes);
	InitAllEnemy(game.all_enemy);
	InitLocalEnemy(game.all_enemy, game.local_enemy);
	InitMap(game.map);
	SetHerosAndEnemy(game.all_heroes, game.local_enemy, game.view.view_ñentre);
	InitInventory(game.inventory);
	InitShop(game.inventory);
}

void Run_Game(RenderWindow& window)
{
	StructGame game;
	Init(game);
	while (window.isOpen())
	{
		game.time_animation.clock.restart();
		game.time_animation.time = float(game.time_animation.clock.getElapsedTime().asMicroseconds());
		game.time_animation.time = game.time_animation.time / 1000;
		window.clear(sf::Color::White);
		CheckEvent(window, game.key_event, stage_game);
		window.setView(game.view.camera);
		ViewUpdate(game.view, game.time_animation.time, stage_game);
		UpdateInfo(game.info, game.view.view_ñentre);
		if (game.menu.flag.level == 1)
		{
			game.sound.main_menu.setVolume(5);
			if (!game.sound.road_play)
			{
				game.sound.old_road.play();
				game.sound.road_play = 1;
			}
		}
		if (stage_game == -1)
		{
			if (UpeatGameOver(game.end_game, game.view.view_ñentre, game.key_event))
				stage_game = 0;
			DrawGameOver(game.end_game, window, stage_game);
			ReInitParam(game);
		}
		if (stage_game == 0)
		{
			if ((game.key_event.key_escape))
				window.close();
			UpdateMenu(game.menu, game.key_event, stage_game, game.view.view_ñentre);
			DrawMenu(game.menu, window);
			
		}
		if (stage_game == 1)
		{
			UpdeatInventory(game.inventory, game.view.view_ñentre);
			ExplorationMod(game.map, game.key_event, game.inventory, game.sound_effect, stage_game);
			DrawMap(game.map, game.view.view_ñentre, window);
			DrawInventory(game.inventory, window);
			if (game.inventory.food.quantity == 0)
				stage_game = -1;
		}
		if (stage_game == 2)
		{
			int falq = 0;
			falq = BattleMod(game.all_heroes, game.local_enemy[game.map.tile_map_enemy[game.map.hero_pos.x][game.map.hero_pos.y]].enemy, 
				game.view.view_ñentre, game.battle_param, game.key_event, game.sound_effect, window);
			if (falq == 2)
			{
				stage_game = 1;
				game.map.hero_pos = game.map.previous_hero_pos;
				game.inventory.food.quantity -= 5;
				game.inventory.relics.quantity -= 2;
			}
			if (falq == 3)
				stage_game = -1;
			if (falq == 1)
			{
				stage_game = 1;
				game.inventory.gold.quantity +=300;
				game.map.tile_map[game.map.hero_pos.x][game.map.hero_pos.y] = 0;
			}
		}		
		if (stage_game == 3)
		{
			ShopMode(game.inventory, game.key_event, game.view.view_ñentre, game.sound_effect, stage_game);
			DrawShop(game.inventory, window);
		}
		if (stage_game == 4)
		{
			UpdateCampfire(game.campfire, game.view.view_ñentre);
			UpdeatInventory(game.inventory, game.view.view_ñentre);
			CampfireMod(game.all_heroes, game.inventory, game.key_event, game.sound_effect);
			DrawCampfire(game.campfire, game.inventory, window);
			if (game.key_event.key_escape)
				stage_game = 1;
		}
		PlaySound(game.sound, stage_game);
		DrawInfo(game.info, stage_game, game.key_event, game.map.tile_map[game.map.hero_pos.x][game.map.hero_pos.y], window);
		CallInfo(game.info, stage_game, game.battle_param.jump_step, window);
		//std::cout << stage_game;
		//DrawGame(window, menu, battle_param, all_heroes, local_enemy[5].enemy);
		window.draw(game.info.key_info.sprite);
		window.display();
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	sf::RenderWindow window(sf::VideoMode(SIZE_WINDOW.x, SIZE_WINDOW.y), "A dark castle", sf::Style::Fullscreen);
	Run_Game(window);
	return 0;
}
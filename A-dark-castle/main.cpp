#include "const.h"
using namespace sf;

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
	SetHerosAndEnemy(game.all_heroes, game.local_enemy, game.view.view_�entre);
	InitInventory(game.inventory);
	InitShop(game.inventory);
	InitSound(game.sound);
	game.stage_game = 0;
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
	SetHerosAndEnemy(game.all_heroes, game.local_enemy, game.view.view_�entre);
	InitInventory(game.inventory);
	InitShop(game.inventory);
}
void WorkGame(StructGame& game, RenderWindow& window)
{
	if (game.menu.flag.level == 1)
	{
		game.sound.main_menu.setVolume(5);
		if (!game.sound.road_play)
		{
			game.sound.old_road.play();
			game.sound.road_play = 1;
		}
	}
	if (game.stage_game == -1)
	{
		if (UpeatGameOver(game.end_game, game.view.view_�entre, game.key_event))
			game.stage_game = 0;
		DrawGameOver(game.end_game, window, game.stage_game);
		ReInitParam(game);
	}
	if (game.stage_game == 0)
	{
		if ((game.key_event.key_escape))
			window.close();
		UpdateMenu(game.menu, game.key_event, game.stage_game, game.view.view_�entre);
		DrawMenu(game.menu, window);
	}
	if (game.stage_game == 1)
	{
		UpdeatInventory(game.inventory, game.view.view_�entre);
		ExplorationMod(game.map, game.key_event, game.inventory, game.sound_effect, game.stage_game);
		DrawMap(game.map, game.view.view_�entre, window);
		DrawInventory(game.inventory, window);
		if (game.inventory.food.quantity == 0)
			game.stage_game = -1;
	}
	if (game.stage_game == 2)
	{
		int falq = 0;
		falq = BattleMod(game.all_heroes, game.local_enemy[game.map.tile_map_enemy[game.map.hero_pos.x][game.map.hero_pos.y]].enemy,
			game.view.view_�entre, game.battle_param, game.key_event, game.sound_effect, window);
		if (falq == 2)
		{
			game.stage_game = 1;
			game.map.hero_pos = game.map.previous_hero_pos;
			game.inventory.food.quantity -= 5;
			game.inventory.relics.quantity -= 2;
		}
		if (falq == 3)
			game.stage_game = -1;
		if (falq == 1)
		{
			game.stage_game = 1;
			game.inventory.gold.quantity += 300;
			game.map.tile_map[game.map.hero_pos.x][game.map.hero_pos.y] = 0;
		}
	}
	if (game.stage_game == 3)
	{
		ShopMode(game.inventory, game.key_event, game.view.view_�entre, game.sound_effect, game.stage_game);
		DrawShop(game.inventory, window);
	}
	if (game.stage_game == 4)
	{
		UpdateCampfire(game.campfire, game.view.view_�entre);
		UpdeatInventory(game.inventory, game.view.view_�entre);
		CampfireMod(game.all_heroes, game.inventory, game.key_event, game.sound_effect);
		DrawCampfire(game.campfire, game.inventory, window);
		if (game.key_event.key_escape)
			game.stage_game = 1;
	}
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
		CheckEvent(window, game.key_event, game.stage_game);
		window.setView(game.view.camera);
		ViewUpdate(game.view, game.time_animation.time, game.stage_game);
		UpdateInfo(game.info, game.view.view_�entre);
		WorkGame(game, window);
		PlaySound(game.sound, game.stage_game);
		DrawInfo(game.info, game.stage_game, game.key_event, game.map.tile_map[game.map.hero_pos.x][game.map.hero_pos.y], window);
		CallInfo(game.info, game.stage_game, game.battle_param.jump_step, window);
		CheckGoodEnd(game.stage_game, game.map.pos_treasure, game.map.tile_map, game.end_game);
		window.draw(game.info.key_info.sprite);
		window.display();
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	sf::RenderWindow window(sf::VideoMode(SIZE_WINDOW.x, SIZE_WINDOW.y), "A dark castle"
		//,sf::Style::Fullscreen
		);
	Run_Game(window);
	return 0;
}
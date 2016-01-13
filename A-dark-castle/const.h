#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "menu.h"
#include "view.h"

#include "heroes.h"
#include "battle.h"
#include "event.h"
#include "map.h"
#include "inventory.h"
#include "Sound.h"
#include "campfire.h"
#include "info.h"
#include "end.h"

using namespace sf;
const Vector2i SIZE_WINDOW = { 1400, 800 };
struct StructTime
{
	Clock clock;
	float time;
};
struct StructGame
{
	int stage_game;
	StructSound sound_effect;
	StructInfo info;
	StructCampfire campfire;
	StructEndGame end_game;
	StructView view;
	StructMenu menu;
	StructMap map;
	StructEvent key_event;
	StructAllEnemy all_enemy;
	StructLocalEnemy local_enemy[ENEMY_COUNT+1];
	StructAllHeroes all_heroes;
	StructBattleParam battle_param;
	StructTime time_animation;
	StructInventory inventory;
	StructMusic sound;
};


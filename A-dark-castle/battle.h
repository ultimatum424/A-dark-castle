#pragma once
#include <SFML\Graphics.hpp>
#include "heroes.h"
#include "event.h"

using namespace sf;

struct StructBattleImage
{
	struct StructImages
	{
		Image image;
		Texture texture;
		Sprite sprite;
	};
	Image image_battle;
	Texture image_texture;
	StructImages background;
	StructImages blackout;
	RectangleShape sh;
	StructImages eclipse;
};
struct StructBattleParam
{
	int jump_step;
	Clock clock_battle;
	float battle_time;
	StructBattleImage battle_image;
};

void InitBattleImages(StructBattleImage& battle_image);
void InitBattleParam(StructBattleParam& battle_param);
void UpdeatBattleImages(StructBattleImage& battle_image, Vector2f view_ñentre);
void UpdeatBattle(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre);
void UpdeatPercks(StructAllHeroes& all_heroes, Vector2f view_ñentre);
void OutHpInfo(Structheroes& hero, Vector2f view_ñentre, int num, RenderWindow& window);
void DrawBattleImages(StructBattleParam battle_param, StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, RenderWindow& window);
int AttackModeEnemy(StructAllHeroes& all_heroes, StructEnemy& enemy);
int BattleMod(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, StructBattleParam& battle_param, StructEvent key_event, RenderWindow& window);
#pragma once
#include <SFML\Graphics.hpp>
#include "heroes.h"
#include "event.h"
#include "Sound.h"
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
	Font font;
	Text text;
	int jump_step;
	Clock clock_battle;
	float battle_time;
	StructBattleImage battle_image;
};

void InitBattleImages(StructBattleImage& battle_image);
void InitBattleParam(StructBattleParam& battle_param);
void UpdeatBattleImages(StructBattleImage& battle_image, Vector2f view_�entre);
void UpdeatBattle(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_�entre);
void UpdeatPercks(StructAllHeroes& all_heroes, Vector2f view_�entre);
void OutHpInfo(Structheroes& hero, Vector2f view_�entre, int num, RenderWindow& window);
void DrawBattleImages(StructBattleParam battle_param, StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_�entre, RenderWindow& window);
int CheckDieHero(Structheroes& hero, int& jump_step);
int CheckDieAllHero(StructAllHeroes& all_heroes);
bool AttackModeEnemy(StructAllHeroes& all_heroes, StructEnemy& enemy, StructSound& sound_effect);
int CheckDieEnemy(StructEnemy enemy[3]);
int BattleMod(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_�entre, StructBattleParam& battle_param, StructEvent key_event, StructSound& sound_effect, RenderWindow& window);
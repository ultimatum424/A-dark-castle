#pragma once
#include "event.h"
#include <SFML\Graphics.hpp>
using namespace sf;

struct StructMenu
{
	struct StructImage
	{
		Image image;
		Texture texture;
		Sprite sprite;
	};
	struct StructFlag
	{
		int menu_item;
		int level;
	} flag;
	StructImage background;
	StructImage castle;
	StructImage map;
	StructImage city;
	Font font;
	Text level;
	Text shop;
	Text exit;
};


void InitMenu(StructMenu& menu);
void UpdateMenu(StructMenu& menu, StructEvent key_event, int& stage_game, Vector2f view_ñentre);
void DrawMenu(StructMenu menu, RenderWindow& window);



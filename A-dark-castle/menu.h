#pragma once

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
	Text text_castle;
};


void InitMenu(StructMenu& menu, Vector2f view_ñentre);
void UpdateMenu(StructMenu& menu);
void DrawMenu(StructMenu menu, RenderWindow& window);



#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <sstream>
#include "event.h"	
#include "Sound.h"
using namespace sf;
const int QUANTITY = 15;
struct StructInventory
{
	struct StructImagesInventory
	{
		Image image;
		Texture texture;
	};
	struct StructCellInventory
	{
		Sprite sprite;
		int quantity;
		Text text;
		Vector2i pos;
		Vector2i size;
	};
	struct StructShop
	{
		Sprite shop_background;
		int shop_cell;
		Text food_gold;
		Text relics_gold;
	};
	StructImagesInventory image;
	StructImagesInventory image_shop;
	StructCellInventory food;
	StructCellInventory relics;
	StructCellInventory gold;
	StructShop shop;
	Font font;
	
};

void InitInventoryElement(StructInventory::StructCellInventory& element, Texture& texture, Font& font);
void InitInventory(StructInventory& inventory);
void UpdeatInventory(StructInventory& inventory, Vector2f view_ñentre);
void DrawInventory(StructInventory& inventory, RenderWindow& window);
void InitShop(StructInventory& inventory);
void UpdeatShop(StructInventory& inventory, Vector2f view_ñentre);
void DrawShop(StructInventory& inventory, RenderWindow& window);
void ShopMode(StructInventory& inventory, StructEvent key_event, Vector2f view_ñentre, StructSound& sound_effect, int& stage_game);
#pragma once
#include <SFML\Graphics.hpp>
#include "event.h"
#include "heroes.h"
#include "inventory.h"

using namespace sf;

struct StructCampfire
{
	struct StructCapmImage
	{
		Image image;
		Texture texture;
		Sprite sprite;
	}camp_image;
};

void InitCampfire(StructCampfire& campfire);
void UpdateCampfire(StructCampfire& campfire, Vector2f view_ñentre);
void CampfireMod(StructAllHeroes& all_heroes, StructInventory& inventory, StructEvent key_event);
void DrawCampfire(StructCampfire& campfire, StructInventory& inventory, RenderWindow& window);
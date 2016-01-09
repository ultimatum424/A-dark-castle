#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "event.h"

using namespace sf;

struct StructImagesInfo
{
	bool out;
	Image image;
	Texture texture;
	Sprite sprite;
};
struct StructInfo
{
	int page;
	StructImagesInfo skill_crusader;
	StructImagesInfo skill_rogure;
	StructImagesInfo skill_wizard;
	StructImagesInfo skill_mage;
	StructImagesInfo resources;
	StructImagesInfo chest;
	StructImagesInfo door;
	StructImagesInfo key_info;
	StructImagesInfo exploration;
	StructImagesInfo battle;
	StructImagesInfo shop;
	StructImagesInfo campfire;
};

void InitInfo(StructImagesInfo& image_info, std::string file);
void InitAllInfo(StructInfo& info);
void UpdateInfo(StructInfo& info, Vector2f view_ñentre);
void DrawInfo(StructInfo& info, int stage_game, StructEvent key_event, int cell_map, RenderWindow& window);
void CallInfo(StructInfo& info, int stage_game, int jump_stage, RenderWindow& window);
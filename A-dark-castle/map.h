#pragma once
#include <SFML\Graphics.hpp>
#include "event.h"
using namespace sf;
const int MAP_SIZE = 15;
const int ENEMY_COUNT = 15;
const int CHEST_COUNT = 10;
const int DOOR_COUNT = 5;
const int TREASURE_COUNT = 1;
// -2 - граница
// -1 - не исследованно
//  0 - пусто
//  1 - враг
//  2 - сундук
//  3 - дверь
//  4 - сокровище
//  5 - игрок


struct StructMap
{
	int tile_map[MAP_SIZE][MAP_SIZE];
	int tile_map_visible[MAP_SIZE][MAP_SIZE];
	struct StructImageMap
	{
		int size_x;
		int size_y;
		Image image;
		Texture texture;
		Sprite sprite;
	};
	StructImageMap map;
	StructImageMap room;
	StructImageMap image_inventory;
	Vector2i hero_pos;
	Vector2i previous_hero_pos;
};

void InitImageMap(StructMap& map);
void InitMap(int tile_map[MAP_SIZE][MAP_SIZE]);
void InitMapVisible(int tile_map_visible[MAP_SIZE][MAP_SIZE]);
void InitMap(StructMap& map);
void DrawMap(StructMap& map, RenderWindow& window);
void OpeningMap(StructMap& map);
void DrawRoom(StructMap& map, Vector2f view_сentre, RenderWindow& window);
void ExplorationMod(StructMap& map, StructEvent key_event);
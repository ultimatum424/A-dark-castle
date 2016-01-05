#include "map.h"
#include "event.h"
#include <ctime>
#include <iostream>

void InitMapReal(int tile_map[MAP_SIZE][MAP_SIZE])
{
	srand(time(0));
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			tile_map[i][j] = -1;
		}
	}
	for (int i = 0; i < MAP_SIZE; i++)
	{
		//tile_map[i][0] = -2;
		//tile_map[i][MAP_SIZE - 1] = -2;
		//tile_map[0][i] = -2;
		//tile_map[MAP_SIZE - 1][i] = -2;
	}
	tile_map[0][0] = 0;
	// расставляем врагов
	int temp_count_enemy = ENEMY_COUNT;
	while (temp_count_enemy != 0)
	{
		int secret_x = (rand() % MAP_SIZE);
		int secret_y = (rand() % MAP_SIZE);
		if (tile_map[secret_x][secret_y] == -1)
		{
			tile_map[secret_x][secret_y] = 1;
			temp_count_enemy--;
		}
	}
	// расставляем сундуки
	int temp_count_chest = CHEST_COUNT;
	while (temp_count_chest != 0)
	{
		int secret_x = (rand() % MAP_SIZE - 1) + 1;
		int secret_y = (rand() % MAP_SIZE - 1) + 1;
		if (tile_map[secret_x][secret_y] == -1)
		{
			tile_map[secret_x][secret_y] = 2;
			temp_count_chest--;
		}
	}
	// расставляем двери
	int temp_count_door = DOOR_COUNT;
	while (temp_count_door != 0)
	{
		int secret_x = (rand() % MAP_SIZE - 1) + 1;
		int secret_y = (rand() % MAP_SIZE - 1) + 1;
		if (tile_map[secret_x][secret_y] == -1)
		{
			tile_map[secret_x][secret_y] = 3;
			temp_count_door--;
		}
	}
	// раставляем сокровище
	int temp_count_treasure = TREASURE_COUNT;
	while (temp_count_treasure != 0)
	{
		int secret_x = (rand() % MAP_SIZE - 1) + 1;
		int secret_y = (rand() % MAP_SIZE - 1) + 1;
		if (tile_map[secret_x][secret_y] == -1)
		{
			tile_map[secret_x][secret_y] = 4;
			temp_count_treasure--;
		}
	}
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			std::cout << tile_map[i][j] << " ";
		}
		std::cout << "\n";
	}
	//составляем карты для игрока
}
void InitMapVisible(int tile_map_visible[MAP_SIZE][MAP_SIZE])
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			tile_map_visible[i][j] = -1;
		}
	}
	tile_map_visible[0][0] = 5;
}
void InitImageMap(StructMap& map)
{
	map.map.image.loadFromFile("../images/exploration/map.png");
	map.map.texture.loadFromImage(map.map.image);
	map.map.sprite.setTexture(map.map.texture);
	map.map.size_x = 64;
	map.map.size_y = 64;

	map.room.image.loadFromFile("../images/exploration/room.png");
	map.room.texture.loadFromImage(map.room.image);
	map.room.sprite.setTexture(map.room.texture);
	map.room.size_x = 720;
	map.room.size_y = 720;

	map.image_inventory.image.loadFromFile("../images/exploration/inventory.png");
	map.image_inventory.texture.loadFromImage(map.image_inventory.image);
	map.image_inventory.sprite.setTexture(map.image_inventory.texture);
	map.image_inventory.size_x = 72;
	map.image_inventory.size_y = 144;
}
void InitMap(StructMap& map)
{
	map.hero_pos = { 0, 0 };
	InitMapReal(map.tile_map);
	InitMapVisible(map.tile_map_visible);
	InitImageMap(map);
}
void DrawMap(StructMap& map, RenderWindow& window)
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (map.tile_map_visible[i][j] == -1)
				map.map.sprite.setTextureRect((IntRect(0, 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 0)
				map.map.sprite.setTextureRect((IntRect(map.map.size_x, 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 1)
				map.map.sprite.setTextureRect((IntRect((map.map.size_x * 4), 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 2)
				map.map.sprite.setTextureRect((IntRect((map.map.size_x * 2), 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 3)
				map.map.sprite.setTextureRect((IntRect((map.map.size_x * 3), 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 4)
				map.map.sprite.setTextureRect((IntRect((map.map.size_x * 5), 0, map.map.size_x, map.map.size_y)));
			else if (map.tile_map_visible[i][j] == 5)
				map.map.sprite.setTextureRect((IntRect((map.map.size_x * 6), 0, map.map.size_x, map.map.size_y)));
			map.map.sprite.setPosition((i * map.map.size_x), (j * map.map.size_y));
			window.draw(map.map.sprite);
		}
	}
	
}
void DrawRoom(StructMap& map, Vector2f view_сentre, RenderWindow& window)
{
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 0) || (map.tile_map[map.hero_pos.x][map.hero_pos.y] == -1))
		map.room.sprite.setTextureRect(IntRect(0, 0, map.room.size_x, map.room.size_y));
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 1))
		map.room.sprite.setTextureRect(IntRect((map.room.size_x * 5), 0, map.room.size_x, map.room.size_y));
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 2))
		map.room.sprite.setTextureRect(IntRect((map.room.size_x * 1), 0, map.room.size_x, map.room.size_y));
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 3))
		map.room.sprite.setTextureRect(IntRect((map.room.size_x * 3), 0, map.room.size_x, map.room.size_y));
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 4))
		map.room.sprite.setTextureRect(IntRect((map.room.size_x * 6), 0, map.room.size_x, map.room.size_y));
	map.room.sprite.setScale(0.7, 0.7);
	map.room.sprite.setPosition(view_сentre.x + 196, view_сentre.y - 400);
	window.draw(map.room.sprite);
}
void OpeningMap(StructMap& map)
{
	if ((map.hero_pos.x - 1) >= 0)
		map.tile_map_visible[map.hero_pos.x - 1][map.hero_pos.y] = map.tile_map[map.hero_pos.x - 1][map.hero_pos.y];
	if ((map.hero_pos.y - 1) >= 0)
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y - 1] = map.tile_map[map.hero_pos.x][map.hero_pos.y - 1];
	if (((map.hero_pos.x - 1) >= 0) && ((map.hero_pos.y - 1) >= 0))
		map.tile_map_visible[map.hero_pos.x - 1][map.hero_pos.y - 1] = map.tile_map[map.hero_pos.x - 1][map.hero_pos.y - 1];
	if ((map.hero_pos.x + 1) < MAP_SIZE)
		map.tile_map_visible[map.hero_pos.x + 1][map.hero_pos.y] = map.tile_map[map.hero_pos.x + 1][map.hero_pos.y];
	if ((map.hero_pos.y + 1) < MAP_SIZE)
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y + 1] = map.tile_map[map.hero_pos.x][map.hero_pos.y + 1];
	if (((map.hero_pos.x + 1) < MAP_SIZE) && ((map.hero_pos.y + 1) < MAP_SIZE))
		map.tile_map_visible[map.hero_pos.x + 1][map.hero_pos.y + 1] = map.tile_map[map.hero_pos.x + 1][map.hero_pos.y + 1];
}
void ExplorationMod(StructMap& map, StructEvent key_event)
{
	OpeningMap(map);
	if ((map.hero_pos.y + 1 < MAP_SIZE) && (key_event.key_down))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.y++;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
	}
	else if ((map.hero_pos.x +1 < MAP_SIZE) && (key_event.key_right))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.x++;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
	}
	else if ((map.hero_pos.y - 1 >= 0) && (key_event.key_up))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.y--;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
	}
	else if ((map.hero_pos.x - 1 >= 0) && (key_event.key_left))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.x--;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
	}
	std::cout << map.hero_pos.y << "\n";
}
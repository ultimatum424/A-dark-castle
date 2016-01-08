#include "map.h"
#include "event.h"
#include "inventory.h"
#include <ctime>
#include <iostream>

void InitMapReal(int tile_map[MAP_SIZE][MAP_SIZE], int tile_map_enemy[MAP_SIZE][MAP_SIZE])
{
	srand(time(0));
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			tile_map_enemy[i][j] = 0;
			tile_map[i][j] = -1;
		}
	}
	tile_map[0][0] = 0;
	// ðàññòàâëÿåì âðàãîâ
	int temp_count_enemy = ENEMY_COUNT;
	int enemy = 0;
	while (temp_count_enemy != 0)
	{
		int secret_x = (rand() % MAP_SIZE);
		int secret_y = (rand() % MAP_SIZE);
		if (tile_map[secret_x][secret_y] == -1)
		{
			tile_map[secret_x][secret_y] = 1;
			tile_map_enemy[secret_x][secret_y] = enemy;
			enemy++;
			temp_count_enemy--;
		}
	}
	// ðàññòàâëÿåì ñóíäóêè
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
	// ðàññòàâëÿåì äâåðè
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
	// ðàñòàâëÿåì ñîêðîâèùå
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
			std::cout << tile_map_enemy[i][j] << " ";
		}
		std::cout << "\n";
	}
	//ñîñòàâëÿåì êàðòû äëÿ èãðîêà
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

	map.background.image.loadFromFile("../images/exploration/background.png");
	map.background.texture.loadFromImage(map.background.image);
	map.background.sprite.setTexture(map.background.texture);

	map.ramka.image.loadFromFile("../images/exploration/ramka.png");
	map.ramka.texture.loadFromImage(map.ramka.image);
	map.ramka.sprite.setTexture(map.ramka.texture);
}
void InitMap(StructMap& map)
{
	map.hero_pos = { 0, 0 };
	InitMapReal(map.tile_map, map.tile_map_enemy);
	InitMapVisible(map.tile_map_visible);
	InitImageMap(map);
}
void DrawMiniMap(StructMap& map, RenderWindow& window)
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
void DrawRoom(StructMap& map, Vector2f view_ñentre, RenderWindow& window)
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
	map.room.sprite.setPosition(view_ñentre.x + 196, view_ñentre.y - 400);
	window.draw(map.room.sprite);
	map.ramka.sprite.setPosition(view_ñentre.x + 196, view_ñentre.y - 400);
	window.draw(map.ramka.sprite);
}
void DrawMap(StructMap& map, Vector2f view_ñentre, RenderWindow& window)
{
	map.background.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	window.draw(map.background.sprite);
	DrawMiniMap(map, window);
	DrawRoom(map, view_ñentre, window);
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
int MoveHero(StructMap& map, StructEvent key_event)
{
	if ((map.hero_pos.y + 1 < MAP_SIZE) && (key_event.key_down))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.y++;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
		return 1;
	}
	else if ((map.hero_pos.x + 1 < MAP_SIZE) && (key_event.key_right))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.x++;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
		return 1;
	}
	else if ((map.hero_pos.y - 1 >= 0) && (key_event.key_up))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.y--;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
		return 1;
	}
	else if ((map.hero_pos.x - 1 >= 0) && (key_event.key_left))
	{
		map.previous_hero_pos = map.hero_pos;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = map.tile_map[map.hero_pos.x][map.hero_pos.y];
		map.hero_pos.x--;
		map.tile_map_visible[map.hero_pos.x][map.hero_pos.y] = 5;
		return 1;
	}
	return 0;
}
void ExplorationMod(StructMap& map, StructEvent key_event, StructInventory& inventory, int& stage_game)
{
	OpeningMap(map);
	if (inventory.food.quantity)
		inventory.food.quantity -= MoveHero(map, key_event);
	if (key_event.key_escape)
		stage_game = 0;
	//if ((key_event.key_space) && (map.tile_map[map.hero_pos.x][map.hero_pos.y] == 1))
	if ((map.tile_map[map.hero_pos.x][map.hero_pos.y] == 1))
		stage_game = 2;
	if ((key_event.key_space) && (map.tile_map[map.hero_pos.x][map.hero_pos.y] == 3))
		stage_game = 3;
	if ((key_event.key_space) && (map.tile_map[map.hero_pos.x][map.hero_pos.y] == 2))
	{
		inventory.relics.quantity += 5;
		inventory.food.quantity -= 2;
		map.tile_map[map.hero_pos.x][map.hero_pos.y] = 0;
	}
	if (key_event.key_tab)
		stage_game = 4;
}
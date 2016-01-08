#pragma once
#include <SFML\Audio.hpp>
#include <vector>

using namespace std;
using namespace sf;

struct StructMusic
{
	vector<string> sound_files =
	{
		"../sound/ost/",
		"main.ogg",
		"exploration.ogg",
		"battle1.ogg",
		"shop.ogg"
	};
	Music main_menu;
	Music exploration;
	Music shop;
	Music battle;
	int prev_stage;
};

void InitSound(StructMusic& music);
void PlaySound(StructMusic& music, int stage_game);
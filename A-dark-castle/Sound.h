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
		"shop.ogg",
		"Camp_Theme.ogg",
		"old_road.ogg"
	};
	Music old_road;
	Music main_menu;
	Music exploration;
	Music shop;
	Music battle;
	Music campfire;
	int prev_stage;
	bool road_play;
};
struct StructBuffer
{
	SoundBuffer  buffer;
	Sound sound;
};
struct StructSound
{
	StructBuffer cheat;
	StructBuffer eat;
	StructBuffer eat_fire;
	StructBuffer enemy_attack;
	StructBuffer  knife;
	StructBuffer  pistol;
	StructBuffer  buff;
	StructBuffer  hill;
	StructBuffer  next_battle;
	StructBuffer  end_battle;
	StructBuffer  ranged_attack;
	StructBuffer click;
};

void InitSound(StructMusic& music);
void PlaySound(StructMusic& music, int stage_game);
void LoadSoundEffect(StructBuffer& sound, string file);
void InitSoundEffects(StructSound& sound);
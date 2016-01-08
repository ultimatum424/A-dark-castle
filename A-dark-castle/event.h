#include <SFML\Graphics.hpp>
#pragma once
using namespace sf;
struct StructEvent
{
	int key_up;
	int key_down;
	int key_space;
	int key_attack;
	int key_left;
	int key_right;
	int key_escape;
	int key_tab;
};

void CheckEvent(RenderWindow& window, StructEvent& key_event, int stage_game);



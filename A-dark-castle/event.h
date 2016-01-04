#include <SFML\Graphics.hpp>
#pragma once
using namespace sf;
struct StructEvent
{
	int key_up;
	int key_down;
	int key_space;
	int key_attack;
};

void CheckEvent(RenderWindow& window, StructEvent& key_event, int stage_game);



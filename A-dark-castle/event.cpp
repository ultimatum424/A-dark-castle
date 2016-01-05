#include "event.h"
#include <SFML\Graphics.hpp>
using namespace sf;

void CheckEvent(RenderWindow& window, StructEvent& key_event, int stage_game)
{
	Event event;
	key_event = {};
	while (window.pollEvent(event))
	{
		if (stage_game == 0)
		{
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up)
					key_event.key_up = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Down)
					key_event.key_down = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Left)
					key_event.key_left = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Right)
					key_event.key_right = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
					key_event.key_space = 1;
		}
		else if (stage_game == 1)
		{
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up)
					key_event.key_up = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Down)
					key_event.key_down = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Left)
					key_event.key_left = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Right)
					key_event.key_right = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
					key_event.key_space = 1;
		}
		else if (stage_game == 2)
		{
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Num1)
					key_event.key_attack = 1;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Num2)
					key_event.key_attack = 2;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Num3)
					key_event.key_attack = 3;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Num4)
					key_event.key_attack = 4;
		}
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
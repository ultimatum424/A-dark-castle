#include "event.h"
#include <SFML\Graphics.hpp>
using namespace sf;

void CheckEvent(RenderWindow& window, StructEvent& key_event, int stage_game)
{
	Event event;
	key_event = {};
	while (window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::LShift)
				key_event.key_shift = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::LAlt)
				key_event.key_alt = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Tab)
				key_event.key_tab = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Up)
				key_event.key_up = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Down)
				key_event.key_down = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Space)
				key_event.key_space = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Escape)
				key_event.key_escape = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Left)
				key_event.key_left = 1;
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Right)
				key_event.key_right = 1;
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
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
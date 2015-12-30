#include "event.h"
#include <SFML\Graphics.hpp>
using namespace sf;

void CheckEvent(RenderWindow& window, StructEvent& key_event)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
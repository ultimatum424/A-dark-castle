#pragma once

struct StructEvent
{
	int key_up;
	int key_down;
};
void CheckEvent(RenderWindow& window, StructEvent& key_event, Event event);


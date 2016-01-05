#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

struct StructView
{
	Vector2f view_ñentre;
	View camera;
	const Vector2f SIZE_VIEW = { 1400, 800 };
	const Vector2f CENTRE = { 700, 400 };
};
void SetView(StructView& view);
void ViewUpdate(StructView& view, float time, int stage_game);


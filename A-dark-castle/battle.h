#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

struct StructBattleImage
{
	Sprite background;
	Sprite blackout;
};

void InitBattleImages(StructBattleImage& battle_image);
void UpdeatBattleImages(StructBattleImage& battle_image, Vector2f view_ñentre);
#include "battle.h"

void InitBattleImages(StructBattleImage& battle_image)
{
	Image image;
	Texture texture;
	image.loadFromFile("../images/battle/weald-back.png");
	texture.loadFromImage(image);
	battle_image.background.setTexture(texture);
	////////////////////////////////////////////////////////
	image.loadFromFile("../images/battle/blackout.png");
	texture.loadFromImage(image);
	battle_image.blackout.setTexture(texture);
}

void UpdeatBattleImages(StructBattleImage& battle_image, Vector2f view_ñentre)
{
	battle_image.background.setPosition((view_ñentre.x - view_ñentre.x), (view_ñentre.y - view_ñentre.y));
	battle_image.blackout.setPosition((view_ñentre.x - view_ñentre.x), (view_ñentre.y - view_ñentre.y));
}
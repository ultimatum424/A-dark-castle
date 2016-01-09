#include "info.h"


void InitInfo(StructImagesInfo& image_info, std::string file)
{
	image_info.out = 1;
	image_info.image.loadFromFile(file);
	image_info.texture.loadFromImage(image_info.image);
	image_info.sprite.setTexture(image_info.texture);
}
void InitAllInfo(StructInfo& info)
{
	info.page = 0;
	InitInfo(info.skill_crusader, "../images/info/skill_crusader.png");
	InitInfo(info.skill_rogure, "../images/info/skill_rogure.png");
	InitInfo(info.skill_wizard, "../images/info/skill_wizard.png");
	InitInfo(info.skill_mage, "../images/info/skill_mage.png");
	InitInfo(info.resources, "../images/info/resources.png");
	InitInfo(info.chest, "../images/info/chest.png");
	InitInfo(info.door, "../images/info/door.png");
	InitInfo(info.key_info, "../images/info/key.png");
	InitInfo(info.exploration, "../images/info/exploration.png");
	InitInfo(info.battle, "../images/info/battle.png");
	InitInfo(info.campfire, "../images/info/campfire.png");
	InitInfo(info.shop, "../images/info/shop.png");
}
void UpdateInfo(StructInfo& info, Vector2f view_ñentre)
{
	info.battle.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	info.exploration.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	info.campfire.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	info.shop.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
	info.key_info.sprite.setPosition(view_ñentre.x + 700 - info.key_info.image.getSize().x, view_ñentre.y - 400);
}
void DrawInfo(StructInfo& info, int stage_game, StructEvent key_event, int cell_map, RenderWindow& window)
{
	if ((stage_game == 1) && (info.chest.out) && (cell_map == 2))
	{
		window.draw(info.chest.sprite);
		if (key_event.key_shift)
			info.chest.out = 0;
	}
	if ((stage_game == 1) && (info.door.out) && (cell_map == 3))
	{
		window.draw(info.door.sprite);
		if (key_event.key_shift)
			info.door.out = 0;
	}
	if ((stage_game == 1) && (info.exploration.out))
	{
		window.draw(info.exploration.sprite);
		if (key_event.key_shift)
			info.exploration.out = 0;
	}
	if ((stage_game == 2) && (info.battle.out))
	{
		window.draw(info.battle.sprite);
		if (key_event.key_shift)
			info.battle.out = 0;
	}
	if ((stage_game == 3) && (info.shop.out))
	{
		window.draw(info.shop.sprite);
		if (key_event.key_shift)
			info.shop.out = 0;
	}
	if ((stage_game == 4) && (info.campfire.out))
	{
		window.draw(info.campfire.sprite);
		if (key_event.key_shift)
			info.campfire.out = 0;
	}
	
}
void CallInfo(StructInfo& info, int stage_game, int jump_stage, RenderWindow& window)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		if (stage_game == 1)
			window.draw(info.resources.sprite);
		if ((stage_game == 2) && (jump_stage == 1))
			window.draw(info.skill_crusader.sprite);
		if ((stage_game == 2) && (jump_stage == 2))
			window.draw(info.skill_rogure.sprite);
		if ((stage_game == 2) && (jump_stage == 3))
			window.draw(info.skill_wizard.sprite);
		if ((stage_game == 2) && (jump_stage == 4))
			window.draw(info.skill_mage.sprite);
			
	}
}
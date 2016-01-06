#include "battle.h"
#include "heroes.h"
#include "event.h"

#include <iostream>

void InitBattleImages(StructBattleImage& battle_image)
{
	battle_image.background.image.loadFromFile("../images/battle/weald-back.png");
	battle_image.background.texture.loadFromImage(battle_image.background.image);
	battle_image.background.sprite.setTexture(battle_image.background.texture);
	////////////////////////////////////////////////////////
	//battle_image.image_battle.loadFromFile("../images/battle/background.png");
	//battle_image.image_texture.loadFromImage(battle_image.image_battle);
	//battle_image.blackout.setTexture(battle_image.image_texture);
	battle_image.eclipse.image.loadFromFile("../images/battle/eclipse.png");
	battle_image.eclipse.texture.loadFromImage(battle_image.eclipse.image);
	battle_image.eclipse.sprite.setTexture(battle_image.eclipse.texture);
	

}
void InitBattleParam(StructBattleParam& battle_param)
{
	InitBattleImages(battle_param.battle_image);
	battle_param.jump_step = 0;
	battle_param.clock_battle.restart();
	battle_param.battle_time = battle_param.clock_battle.getElapsedTime().asSeconds();
}
void UpdeatBattleImages(StructBattleImage& battle_image, Vector2f view_ñentre)
{
	battle_image.background.sprite.setPosition((view_ñentre.x - 700), (view_ñentre.y - 400));
	battle_image.blackout.sprite.setPosition((view_ñentre.x - 700), (view_ñentre.y - 400));
	battle_image.eclipse.sprite.setPosition((view_ñentre.x - 700), (view_ñentre.y - 400));
}

void UpdeatBattle(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre)
{
	all_heroes.cruasder.battle.batle_sprite = {};
	all_heroes.rogue.battle.batle_sprite = {};
	all_heroes.wizard.battle.batle_sprite = {};
	all_heroes.mage.battle.batle_sprite = {};

	all_heroes.cruasder.battle.stay.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
	all_heroes.rogue.battle.stay.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
	all_heroes.wizard.battle.stay.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
	all_heroes.mage.battle.stay.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

	all_heroes.cruasder.battle.batle_sprite.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
	all_heroes.rogue.battle.batle_sprite.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
	all_heroes.wizard.battle.batle_sprite.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
	all_heroes.mage.battle.batle_sprite.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

	for (int i = 0; i < 3; i++)
	{
		//enemy[i].battle_sprite = enemy[i].stay;
		enemy[i].battle_sprite = {};
		enemy[i].stay.setPosition(view_ñentre.x + 100 + (200 * i), view_ñentre.y + 130);
		enemy[i].battle_sprite.setPosition(view_ñentre.x + 100 + (200 * i), view_ñentre.y + 130);
	}
}

void DrawBattleImages(StructBattleParam battle_param, StructAllHeroes& all_heroes, StructEnemy enemy[3], RenderWindow& window)
{
	window.draw(battle_param.battle_image.background.sprite);
	DrawHeroes(all_heroes, window);
	DrawEnemy(enemy, window);
	if (battle_param.battle_time <= 2)
	{
		window.draw(battle_param.battle_image.eclipse.sprite);
		window.draw(all_heroes.cruasder.battle.batle_sprite);
		window.draw(all_heroes.rogue.battle.batle_sprite);
		window.draw(all_heroes.wizard.battle.batle_sprite);
		window.draw(all_heroes.mage.battle.batle_sprite);
		for (int i = 0; i < 3; i++)
			window.draw(enemy[i].battle_sprite);
	}
}

void BattleMod(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, StructBattleParam& battle_param, int key_attack, RenderWindow& window)
{
	bool flaq = false;
	battle_param.battle_time = battle_param.clock_battle.getElapsedTime().asSeconds();
	UpdeatBattleImages(battle_param.battle_image, view_ñentre);
	if (battle_param.jump_step == 0)
	{
		battle_param.clock_battle.restart();
		battle_param.jump_step = 1;
	}
	if (battle_param.battle_time > 2)
	{
		UpdeatBattle(all_heroes, enemy, view_ñentre);
		if (battle_param.jump_step == 1)
			flaq = AttackModeCrusader(all_heroes, enemy, key_attack);
		if (battle_param.jump_step == 2)
			flaq = AttackModeRogue(all_heroes, enemy, key_attack);
		if (battle_param.jump_step == 3)
			flaq = AttackModeWizard(all_heroes, enemy, key_attack);
		if (battle_param.jump_step == 4)
			flaq = AttackModeMage(all_heroes, key_attack);
		if (flaq)
		{
			battle_param.clock_battle.restart();
			battle_param.jump_step++;
		}
		if (battle_param.jump_step == 5)
			battle_param.jump_step = 0;
	}
	DrawBattleImages(battle_param, all_heroes, enemy, window);
}
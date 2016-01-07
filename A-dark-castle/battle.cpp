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
void UpdeatPercks(StructAllHeroes& all_heroes, Vector2f view_ñentre)
{
	all_heroes.cruasder.battle.ability.setPosition(view_ñentre.x - 700, view_ñentre.y + 125);
	all_heroes.rogue.battle.ability.setPosition(view_ñentre.x - 700, view_ñentre.y + 125);
	all_heroes.wizard.battle.ability.setPosition(view_ñentre.x - 700, view_ñentre.y + 125);
	all_heroes.mage.battle.ability.setPosition(view_ñentre.x - 700, view_ñentre.y + 125);
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
void OutHpInfo(Structheroes& hero, Vector2f view_ñentre, int num, RenderWindow& window)
{
	Vector2f zoom = { 0.75, 0.75 };
	Font font;
	font.loadFromFile("../Fonts/9210.ttf");
	sf::Text Hp("", font, 20);
	Hp.setColor(Color::Black);
	std::ostringstream player_max_HP;
	std::ostringstream playerHP;
	std::ostringstream player_damage;
	std::ostringstream player_armor;
	player_damage << hero.stats.damage;
	player_armor << hero.stats.def;
	player_max_HP << hero.stats.max_hp;
	playerHP << hero.stats.hp;
	Hp.setString("HP: " + playerHP.str() + "/ " + player_max_HP.str() + "	" + "% damage: " + player_damage.str() + "	" + "% armor: " + player_armor.str());
	Hp.setPosition(view_ñentre.x - 100, view_ñentre.y + 70 + (num * 70));
	hero.battle.batle_icon.setScale(zoom);
	hero.battle.batle_icon.setPosition(view_ñentre.x - 180, view_ñentre.y + 55 + (num * 70));
	window.draw(hero.battle.batle_icon);
	window.draw(Hp);
}
void DrawBattleImages(StructBattleParam battle_param, StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, RenderWindow& window)
{
	window.draw(battle_param.battle_image.background.sprite);
	DrawHeroes(all_heroes, window);
	DrawEnemy(enemy, window);
	OutHpInfo(all_heroes.cruasder, view_ñentre, 1, window);
	OutHpInfo(all_heroes.rogue, view_ñentre, 2, window);
	OutHpInfo(all_heroes.wizard, view_ñentre, 3, window);
	OutHpInfo(all_heroes.mage, view_ñentre, 4, window);
	if (battle_param.jump_step == 1)
		window.draw(all_heroes.cruasder.battle.ability);
	if (battle_param.jump_step == 2)
		window.draw(all_heroes.rogue.battle.ability);
	if (battle_param.jump_step == 3)
		window.draw(all_heroes.wizard.battle.ability);
	if (battle_param.jump_step == 4)
		window.draw(all_heroes.mage.battle.ability);
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


int BattleMod(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, StructBattleParam& battle_param, StructEvent key_event, RenderWindow& window)
{
	bool flaq = false;
	battle_param.battle_time = battle_param.clock_battle.getElapsedTime().asSeconds();
	UpdeatBattleImages(battle_param.battle_image, view_ñentre);
	UpdeatPercks(all_heroes, view_ñentre);
	if (key_event.key_escape)
		return 2;
	if (battle_param.jump_step == 0)
	{
		battle_param.clock_battle.restart();
		battle_param.jump_step = 1;
	}
	if (battle_param.battle_time > 2)
	{
		UpdeatBattle(all_heroes, enemy, view_ñentre);
		if (battle_param.jump_step == 1)
			flaq = AttackModeCrusader(all_heroes, enemy, key_event.key_attack);
		if (battle_param.jump_step == 2)
			flaq = AttackModeRogue(all_heroes, enemy, key_event.key_attack);
		if (battle_param.jump_step == 3)
			flaq = AttackModeWizard(all_heroes, enemy, key_event.key_attack);
		if (battle_param.jump_step == 4)
			flaq = AttackModeMage(all_heroes, key_event.key_attack);
		if (flaq)
		{
			battle_param.clock_battle.restart();
			battle_param.jump_step++;
		}
		if (battle_param.jump_step == 5)
			battle_param.jump_step = 0;
	}
	DrawBattleImages(battle_param, all_heroes, enemy, view_ñentre, window);
}
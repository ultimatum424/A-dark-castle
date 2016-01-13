#include "battle.h"

#include <iostream>

void InitBattleImages(StructBattleImage& battle_image)
{
	battle_image.background.image.loadFromFile("../images/battle/weald-back.png");
	battle_image.background.texture.loadFromImage(battle_image.background.image);
	battle_image.background.sprite.setTexture(battle_image.background.texture);
	battle_image.eclipse.image.loadFromFile("../images/battle/eclipse.png");
	battle_image.eclipse.texture.loadFromImage(battle_image.eclipse.image);
	battle_image.eclipse.sprite.setTexture(battle_image.eclipse.texture);
}
void InitBattleParam(StructBattleParam& battle_param)
{
	InitBattleImages(battle_param.battle_image);
	battle_param.font.loadFromFile("../Fonts/9210.ttf");
	battle_param.text.setCharacterSize(25);
	battle_param.text.setColor(Color::Red);
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
		enemy[i].battle_sprite = {};
		enemy[i].stay.setPosition(view_ñentre.x + 100 + (200 * i), view_ñentre.y + 130);
		enemy[i].die.setPosition(view_ñentre.x + 100 + (200 * i), view_ñentre.y + 130);
		enemy[i].attack.setPosition(view_ñentre.x  + (200 * i), view_ñentre.y + 130);
		enemy[i].battle_sprite.setPosition(view_ñentre.x + 100 + (200 * i), view_ñentre.y + 130);
		enemy[i].sq.setSize(Vector2f(float(enemy[i].hp * 3), 10));
		enemy[i].sq.setFillColor(Color::Red);
		enemy[i].sq.setPosition(view_ñentre.x + 350, view_ñentre.y + 200 + (i * 50));
		enemy[i].sq_max.setSize(Vector2f(float(enemy[i].max_hp * 3), 10));
		enemy[i].sq_max.setFillColor(Color::White);
		enemy[i].sq_max.setPosition(view_ñentre.x + 350, view_ñentre.y + 200 + (i * 50));
	}
}
void OutHpInfo(Structheroes& hero, Vector2f view_ñentre, int num, RenderWindow& window)
{
	Vector2f zoom = { 0.75, 0.75 };
	Font font;
	font.loadFromFile("../Fonts/9210.ttf");
	sf::Text Hp("", font, 20);
	Hp.setColor(Color::White);
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
bool AttackModeEnemy(StructAllHeroes& all_heroes, StructEnemy& enemy, StructSound& sound_effect)
{
	bool victim_attatck = 0;
	while (!victim_attatck)
	{
		int damage;
		int heroes_victim = rand() % 4 + 1;
		int amount_damage = rand() % 15 + 1;
		if (heroes_victim == 1)
		{
			damage = int(amount_damage / all_heroes.cruasder.stats.def);
			if (all_heroes.cruasder.stats.hp)
			{
				victim_attatck = 1;
				if (all_heroes.cruasder.stats.hp <= damage)
					all_heroes.cruasder.stats.hp = 0;
				else
					all_heroes.cruasder.stats.hp -= damage;
				all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.get_damage;
				enemy.battle_sprite = enemy.attack;
				enemy.battle_sprite.setPosition(all_heroes.cruasder.battle.stay.getPosition());
				sound_effect.enemy_attack.sound.play();
				return true;
			}
		}
		if (heroes_victim == 2)
		{
			damage = int(amount_damage / all_heroes.rogue.stats.def);
			if (all_heroes.rogue.stats.hp)
			{
				victim_attatck = 1;
				if (all_heroes.rogue.stats.hp <= damage)
					all_heroes.rogue.stats.hp = 0;
				else
					all_heroes.rogue.stats.hp -= damage;
				all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.get_damage;
				enemy.battle_sprite = enemy.attack;
				enemy.battle_sprite.setPosition(all_heroes.rogue.battle.stay.getPosition());
				sound_effect.enemy_attack.sound.play();
				return true;
			}
		}
		if (heroes_victim == 3)
		{
			damage = int(amount_damage / all_heroes.wizard.stats.def);
			if (all_heroes.wizard.stats.hp)
			{
				victim_attatck = 1;
				if (all_heroes.wizard.stats.hp < damage)
					all_heroes.wizard.stats.hp = 0;
				else
					all_heroes.wizard.stats.hp -= damage;
				all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.get_damage;
				enemy.battle_sprite = enemy.attack;
				enemy.battle_sprite.setPosition(all_heroes.wizard.battle.stay.getPosition());
				sound_effect.enemy_attack.sound.play();
				return true;
			}
		}
		if (heroes_victim == 4)
		{
			damage = int(amount_damage / all_heroes.mage.stats.def);
			if (all_heroes.mage.stats.hp)
			{
				victim_attatck = 1;
				if (all_heroes.mage.stats.hp <= damage)
					all_heroes.mage.stats.hp = 0;
				else
					all_heroes.mage.stats.hp -= damage;
				all_heroes.rogue.battle.batle_sprite = all_heroes.mage.battle.get_damage;
				enemy.battle_sprite = enemy.attack;
				enemy.battle_sprite.setPosition(all_heroes.mage.battle.stay.getPosition());
				sound_effect.enemy_attack.sound.play();
				return true;
			}
		}
	}
	return 0;
}
int CheckDieHero(Structheroes& hero)
{
	if (hero.stats.hp == 0)
	{
		hero.battle.stay = hero.battle.die;
		return 1;
	}
	else
		hero.battle.stay.setTextureRect(IntRect(hero.battle.stay_texture.pos_x, hero.battle.stay_texture.pos_y, 
			hero.battle.stay_texture.size_x, hero.battle.stay_texture.size_y));
	return 0;
}
int CheckDieAllHero(StructAllHeroes& all_heroes)
{
	int check = CheckDieHero(all_heroes.cruasder) + CheckDieHero(all_heroes.rogue) +
		CheckDieHero(all_heroes.wizard) + CheckDieHero(all_heroes.mage);
	if (check == 4)
		return 1;
	else
		return 0;
}
int CheckDieEnemy(StructEnemy enemy[3])
{
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i].hp == 0)
			enemy[i].stay = enemy[i].die;
	}
	if ((enemy[0].hp + enemy[1].hp + enemy[2].hp) == 0)
		return 1;
	else return 0;
}
int BattleMod(StructAllHeroes& all_heroes, StructEnemy enemy[3], Vector2f view_ñentre, StructBattleParam& battle_param, 
	StructEvent key_event, StructSound& sound_effect, RenderWindow& window)
{
	bool flaq = 0;
	battle_param.battle_time = battle_param.clock_battle.getElapsedTime().asSeconds();
	UpdeatBattleImages(battle_param.battle_image, view_ñentre);
	UpdeatPercks(all_heroes, view_ñentre);
	battle_param.text.setPosition(view_ñentre.x, view_ñentre.y);
	if (key_event.key_escape)
		return 2;	
	if (battle_param.jump_step == 0)
	{
		sound_effect.next_battle.sound.play();
		battle_param.jump_step = 1;
	}
	if (battle_param.battle_time > 2)
	{
		if (CheckDieAllHero(all_heroes))
			return 3;
		if (CheckDieEnemy(enemy))
			return 1;
		UpdeatBattle(all_heroes, enemy, view_ñentre);
		
		if ((battle_param.jump_step == 1) && (all_heroes.cruasder.stats.hp))
			flaq = AttackModeCrusader(all_heroes, enemy, sound_effect, key_event.key_attack);
		if ((battle_param.jump_step == 2) && (all_heroes.rogue.stats.hp))
			flaq = AttackModeRogue(all_heroes, enemy, sound_effect, key_event.key_attack);
		if ((battle_param.jump_step == 3) && (all_heroes.wizard.stats.hp))
			flaq = AttackModeWizard(all_heroes, enemy, sound_effect, key_event.key_attack);
		if ((battle_param.jump_step == 4) && (all_heroes.mage.stats.hp))
			flaq = AttackModeMage(all_heroes, sound_effect, key_event.key_attack);
		if ((battle_param.jump_step == 5) && (enemy[0].hp))
			flaq = AttackModeEnemy(all_heroes, enemy[0], sound_effect);
		if ((battle_param.jump_step == 6) && (enemy[1].hp))
			flaq = AttackModeEnemy(all_heroes, enemy[1], sound_effect);
		if ((battle_param.jump_step == 7) && (enemy[2].hp))
			flaq = AttackModeEnemy(all_heroes, enemy[2], sound_effect);
		if ((battle_param.jump_step == 1) && (all_heroes.cruasder.stats.hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 2) && (all_heroes.rogue.stats.hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 3) && (all_heroes.wizard.stats.hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 4) && (all_heroes.mage.stats.hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 5) && (enemy[0].hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 6) && (enemy[1].hp == 0))
			battle_param.jump_step++;
		if ((battle_param.jump_step == 7) && (enemy[2].hp == 0))
			battle_param.jump_step++;
		if (flaq)
		{
			battle_param.clock_battle.restart();
			battle_param.jump_step++;
		}
		if (battle_param.jump_step == 8)
			battle_param.jump_step = 0;
	}
	DrawBattleImages(battle_param, all_heroes, enemy, view_ñentre, window);
	return 0;
}
#include <cstdlib>
#include <ctime>
#include "heroes.h"
#include "map.h"
#include <iostream>


void InitHeroCrusader(Structheroes& hero, vector<string> file)
{
	hero.battle.image.loadFromFile(file[0]);
	hero.battle.texture.loadFromImage(hero.battle.image);
	hero.battle.stay.setTexture(hero.battle.texture);
	hero.battle.attack1.setTexture(hero.battle.texture);
	hero.battle.attack2.setTexture(hero.battle.texture);
	hero.battle.attack3.setTexture(hero.battle.texture);
	hero.battle.attack4.setTexture(hero.battle.texture);
	hero.battle.get_damage.setTexture(hero.battle.texture);

	hero.battle.stay.setTextureRect(IntRect(0, 0, 181, 430));
	hero.battle.attack1.setTextureRect(IntRect(0, 430, 297, 325));
	hero.battle.attack2.setTextureRect(IntRect(0, 755, 235, 340));
	hero.battle.attack3.setTextureRect(IntRect(0, 1095, 267, 520));	
	hero.battle.attack4.setTextureRect(IntRect(0, 1615, 453, 233));
	hero.battle.get_damage.setTextureRect(IntRect(0, 1848, 181, 361));

	hero.battle.stay.setOrigin(0, 430);
	hero.battle.attack1.setOrigin(0, 325);
	hero.battle.attack2.setOrigin(0, 340);
	hero.battle.attack3.setOrigin(0, 520);
	hero.battle.attack4.setOrigin(0, 233);
	hero.battle.get_damage.setOrigin(0, 361);
	hero.battle.image_perks.loadFromFile(file[1]);
	hero.battle.texture_perks.loadFromImage(hero.battle.image_perks);
	hero.battle.ability.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTextureRect(IntRect(415, 190, 85, 85));
	hero.stats.max_hp = hero.stats.hp = 60;
	hero.stats.def = 1;
	hero.stats.damage = 0.5;
}
void InitHeroRogue(Structheroes& hero, vector<string> file)
{
	hero.battle.image.loadFromFile(file[0]);
	hero.battle.texture.loadFromImage(hero.battle.image);

	hero.battle.stay.setTexture(hero.battle.texture);
	hero.battle.attack1.setTexture(hero.battle.texture);
	hero.battle.attack2.setTexture(hero.battle.texture);
	hero.battle.attack3.setTexture(hero.battle.texture);
	hero.battle.attack4.setTexture(hero.battle.texture);
	hero.battle.get_damage.setTexture(hero.battle.texture);

	hero.battle.stay.setTextureRect(IntRect(0, 0, 201, 306));
	hero.battle.attack1.setTextureRect(IntRect(0, 306, 349, 300));	
	hero.battle.attack2.setTextureRect(IntRect(0, 606, 324, 268));	
	hero.battle.attack3.setTextureRect(IntRect(0, 874, 349, 300));
	hero.battle.attack4.setTextureRect(IntRect(0, 1174, 342, 236));
	hero.battle.get_damage.setTextureRect(IntRect(0, 1410, 202, 282));

	hero.battle.stay.setOrigin(0, 306);
	hero.battle.attack1.setOrigin(0, 300);
	hero.battle.attack2.setOrigin(0, 268);
	hero.battle.attack3.setOrigin(0, 300);
	hero.battle.attack4.setOrigin(0, 236);
	hero.battle.get_damage.setOrigin(0, 282);

	hero.battle.image_perks.loadFromFile(file[1]);
	hero.battle.texture_perks.loadFromImage(hero.battle.image_perks);
	hero.battle.ability.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTextureRect(IntRect(415, 190, 85, 85));
	hero.stats.max_hp = hero.stats.hp = 40;
	hero.stats.def = 0.25;
	hero.stats.damage = 1.5;
}
void InitHeroWizard(Structheroes& hero, vector<string> file)
{
	hero.battle.image.loadFromFile(file[0]);
	hero.battle.texture.loadFromImage(hero.battle.image);

	hero.battle.stay.setTexture(hero.battle.texture);
	hero.battle.attack1.setTexture(hero.battle.texture);
	hero.battle.attack2.setTexture(hero.battle.texture);
	hero.battle.attack3.setTexture(hero.battle.texture);
	hero.battle.attack4.setTexture(hero.battle.texture);
	hero.battle.get_damage.setTexture(hero.battle.texture);
	hero.battle.stay.setTextureRect(IntRect(0, 0, 199, 316));
	hero.battle.attack1.setTextureRect(IntRect(0, 316, 228, 303));
	hero.battle.attack2.setTextureRect(IntRect(0, 619, 199, 316));	
	hero.battle.attack3.setTextureRect(IntRect(0, 935, 199, 316));	
	hero.battle.attack4.setTextureRect(IntRect(0, 1251, 310, 259));	
	hero.battle.get_damage.setTextureRect(IntRect(0, 1510, 212, 298));

	hero.battle.stay.setOrigin(0, 316);
	hero.battle.attack1.setOrigin(0, 303);
	hero.battle.attack2.setOrigin(0, 316);
	hero.battle.attack3.setOrigin(0, 316);
	hero.battle.attack4.setOrigin(0, 259);
	hero.battle.get_damage.setOrigin(0, 298);

	hero.battle.image_perks.loadFromFile(file[1]);
	hero.battle.texture_perks.loadFromImage(hero.battle.image_perks);
	hero.battle.ability.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTextureRect(IntRect(415, 190, 85, 85));
	hero.stats.max_hp = hero.stats.hp = 30;
	hero.stats.def = 0.5;
	hero.stats.damage = 0.5;
}
void InitHeroMage(Structheroes& hero, vector<string> file)
{
	hero.battle.image.loadFromFile(file[0]);
	hero.battle.texture.loadFromImage(hero.battle.image);
	hero.battle.stay.setTexture(hero.battle.texture);
	hero.battle.attack1.setTexture(hero.battle.texture);
	hero.battle.attack2.setTexture(hero.battle.texture);
	hero.battle.attack3.setTexture(hero.battle.texture);
	hero.battle.attack4.setTexture(hero.battle.texture);
	hero.battle.get_damage.setTexture(hero.battle.texture);
	hero.battle.stay.setTextureRect(IntRect(0, 0, 181, 341));
	hero.battle.attack1.setTextureRect(IntRect(0, 341, 197, 395));
	hero.battle.attack2.setTextureRect(IntRect(0, 736, 197, 395));	
	hero.battle.attack3.setTextureRect(IntRect(0, 1131, 197, 395));	
	hero.battle.attack4.setTextureRect(IntRect(0, 1526, 181, 408));
	hero.battle.get_damage.setTextureRect(IntRect(0, 1934, 187, 311));

	hero.battle.stay.setOrigin(0, 341);
	hero.battle.attack1.setOrigin(0, 395);
	hero.battle.attack2.setOrigin(0, 395);
	hero.battle.attack3.setOrigin(0, 395);
	hero.battle.attack4.setOrigin(0, 408);
	hero.battle.get_damage.setOrigin(0, 311);

	hero.battle.image_perks.loadFromFile(file[1]);
	hero.battle.texture_perks.loadFromImage(hero.battle.image_perks);
	hero.battle.ability.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTexture(hero.battle.texture_perks);
	hero.battle.batle_icon.setTextureRect(IntRect(415, 190, 85, 85));
	hero.stats.max_hp = hero.stats.hp = 30;
	hero.stats.def = 0.5;
	hero.stats.damage = 0.5;
}

void InitHeroes(StructAllHeroes& all_heroes)
{
	vector<string> files = { "../images/heroes/crusader/attack.png", "../images/heroes/crusader/perks.png" };
	InitHeroCrusader(all_heroes.cruasder, files);
	files = { "../images/heroes/rogue/battle.png", "../images/heroes/rogue/perks.png" };
	InitHeroRogue(all_heroes.rogue, files);
	files = { "../images/heroes/wizard/battle.png", "../images/heroes/wizard/perks.png" };
	InitHeroWizard(all_heroes.wizard, files);
	files = { "../images/heroes/mage/battle.png", "../images/heroes/mage/perks.png" };
	InitHeroMage(all_heroes.mage, files);
}

void InitSkeleton(StructEnemy& enemy, string file)
{
	
	enemy.image.loadFromFile(file);
	enemy.texture.loadFromImage(enemy.image);

	enemy.stay.setTexture(enemy.texture);
	enemy.get_damage.setTexture(enemy.texture);
	enemy.attack.setTexture(enemy.texture);
	enemy.stay.setTextureRect(IntRect(0, 0, 200, 282));
	enemy.attack.setTextureRect(IntRect(0, 282, 336, 287));
	enemy.get_damage.setTextureRect(IntRect(0, 569, 181, 289));

	enemy.stay.setOrigin(0, 282);
	enemy.get_damage.setOrigin(0, 287);
	enemy.attack.setOrigin(0, 289);
	enemy.hp = 50;
}
void InitBandit(StructEnemy& enemy, string file)
{
	enemy.image.loadFromFile(file);
	enemy.texture.loadFromImage(enemy.image);

	enemy.stay.setTexture(enemy.texture);
	enemy.get_damage.setTexture(enemy.texture);
	enemy.attack.setTexture(enemy.texture);
	enemy.stay.setTextureRect(IntRect(0, 0, 181, 355));
	enemy.attack.setTextureRect(IntRect(0, 385, 431, 254));
	enemy.get_damage.setTextureRect(IntRect(0, 639, 208, 300));

	enemy.stay.setOrigin(0, 385);
	enemy.get_damage.setOrigin(0, 254);
	enemy.attack.setOrigin(0, 331);
	enemy.hp = 50;
}
void InitGhoul(StructEnemy& enemy, string file)
{
	enemy.image.loadFromFile(file);
	enemy.texture.loadFromImage(enemy.image);

	enemy.stay.setTexture(enemy.texture);
	enemy.get_damage.setTexture(enemy.texture);
	enemy.attack.setTexture(enemy.texture);
	enemy.stay.setTextureRect(IntRect(0, 0, 456, 392));
	enemy.attack.setTextureRect(IntRect(0, 392, 445, 397));
	enemy.get_damage.setTextureRect(IntRect(0, 789, 269, 372));

	enemy.stay.setOrigin(0, 392);
	enemy.get_damage.setOrigin(0, 397);
	enemy.attack.setOrigin(0, 372);
	enemy.hp = 50;
}
void InitNecromant(StructEnemy& enemy, string file)
{
	enemy.image.loadFromFile(file);
	enemy.texture.loadFromImage(enemy.image);

	enemy.stay.setTexture(enemy.texture);
	enemy.get_damage.setTexture(enemy.texture);
	enemy.attack.setTexture(enemy.texture);
	enemy.stay.setTextureRect(IntRect(0, 0, 217, 413));
	enemy.attack.setTextureRect(IntRect(0, 434, 438, 309));
	enemy.get_damage.setTextureRect(IntRect(0, 743, 208, 335));

	enemy.stay.setOrigin(0, 434);
	enemy.get_damage.setOrigin(0, 309);
	enemy.attack.setOrigin(0, 335);
	enemy.hp = 50;
}
void InitAllEnemy(StructAllEnemy& all_enemy)
{
	InitSkeleton(all_enemy.skeleton, "../images/enemy/skeleton/skeleton.png");
	InitBandit(all_enemy.bandit, "../images/enemy/bandit/battle.png");
	InitGhoul(all_enemy.ghoul, "../images/enemy/ghoul/battle.png");
	InitNecromant(all_enemy.necromant, "../images/enemy/necromant/battle.png");
}
void InitLocalEnemy(StructAllEnemy& all_enemy, StructLocalEnemy local_enemy[ENEMY_COUNT])
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int secret = rand() % 5;
			//int secret = 2;
			//std::cout << i << "---" << secret << "--" << j << "\n";
			if (secret == 0) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 1) local_enemy[i].enemy[j] = all_enemy.bandit;
			if (secret == 2) local_enemy[i].enemy[j] = all_enemy.bandit;
			if (secret == 3) local_enemy[i].enemy[j] = all_enemy.necromant;
			if (secret == 4) local_enemy[i].enemy[j] = all_enemy.skeleton;
		}
	}
}
void SetHerosAndEnemy(StructAllHeroes& all_heroes, StructLocalEnemy local_enemy[ENEMY_COUNT], Vector2f view_ñentre)
{
		all_heroes.cruasder.battle.stay.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.stay.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.stay.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.stay.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.attack1.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.attack1.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.attack1.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.attack1.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.attack2.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.attack2.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.attack2.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.attack2.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.attack3.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.attack3.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.attack3.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.attack3.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.attack4.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.attack4.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.attack4.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.attack4.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.get_damage.setPosition(view_ñentre.x - 100, view_ñentre.y + 130);
		all_heroes.rogue.battle.get_damage.setPosition(view_ñentre.x - 300, view_ñentre.y + 130);
		all_heroes.wizard.battle.get_damage.setPosition(view_ñentre.x - 500, view_ñentre.y + 130);
		all_heroes.mage.battle.get_damage.setPosition(view_ñentre.x - 700, view_ñentre.y + 130);

		all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.stay;
		all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.stay;
		all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.stay;
		all_heroes.mage.battle.batle_sprite = all_heroes.mage.battle.stay;

	//all_heroes.cruasder.battle.batle_sprite.setPosition(view_ñentre.x, view_ñentre.y + 130);
	//all_heroes.rogue.battle.batle_sprite.setPosition(view_ñentre.x - 200, view_ñentre.y + 130);
	//all_heroes.wizard.battle.batle_sprite.setPosition(view_ñentre.x - 400, view_ñentre.y + 130);
	//all_heroes.mage.battle.batle_sprite.setPosition(view_ñentre.x - 600, view_ñentre.y + 130);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			local_enemy[i].enemy[j].stay.setPosition(view_ñentre.x + 100 + (200 * j), view_ñentre.y + 130);
			local_enemy[i].enemy[j].attack.setPosition(view_ñentre.x + 100 + (200 * j), view_ñentre.y + 130);
			local_enemy[i].enemy[j].get_damage.setPosition(view_ñentre.x + 100 + (200 * j), view_ñentre.y + 130);
			local_enemy[i].enemy[j].battle_sprite = local_enemy[i].enemy[j].stay;
			//local_enemy[i].enemy[j].battle_sprite.setPosition(view_ñentre.x + 200 + (200 * j), view_ñentre.y + 130);
		}
	}
}
bool AttackModeCrusader(StructAllHeroes& all_heroes, StructEnemy enemy[4], int& key_attack)
{
	AttacksCruasder attack_cruasder;
	if (key_attack == 1)
	{
		key_attack = 0;
		all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.attack1;
		if (enemy[0].hp != 0)
			enemy[1].battle_sprite = enemy[0].get_damage;
		attack_cruasder.Attack1(all_heroes.cruasder, enemy[0]);
		return true;
	}
	else if (key_attack == 2)
	{
		all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.attack2;
		attack_cruasder.Attack2(all_heroes.cruasder);
		key_attack = 0;
		return true;
	}
	else if (key_attack == 3) {
		all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.attack3;
		key_attack = 0;
		attack_cruasder.Attack3(all_heroes.cruasder);
		return true;
	}
	else if (key_attack == 4)
	{
		all_heroes.cruasder.battle.batle_sprite = all_heroes.cruasder.battle.attack4;
		if (enemy[0].hp != 0)
			enemy[0].battle_sprite = enemy[0].get_damage;
		attack_cruasder.Attack4(all_heroes.cruasder, enemy[0]);
		key_attack = 0;
		return true;
	}
	return false;
}
bool AttackModeRogue(StructAllHeroes& all_heroes, StructEnemy enemy[4], int& key_attack)
{
	AttacksRogue attack_rouge;
	if (key_attack == 1)
	{
		all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.attack1;
		if (enemy[0].hp != 0)
			enemy[0].battle_sprite = enemy[0].get_damage;
		key_attack = 0;
		attack_rouge.Attack1(all_heroes.rogue, enemy[0]);
		return true;
	}
	else if (key_attack == 2)
	{
		all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.attack2;
		key_attack = 0;
		attack_rouge.Attack2(all_heroes.rogue);
		return true;
	}
	else if (key_attack == 3)
	{
		all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.attack3;
		if (enemy[0].hp != 0)
			enemy[0].battle_sprite = enemy[0].get_damage;
		if (enemy[1].hp != 0)
			enemy[1].battle_sprite = enemy[1].get_damage;
		if (enemy[2].hp != 0)
			enemy[2].battle_sprite = enemy[2].get_damage;
		key_attack = 0;
		attack_rouge.Attack3(enemy[0], enemy[1], enemy[2]);
		return true;
	}
	else if (key_attack == 4)
	{
		all_heroes.rogue.battle.batle_sprite = all_heroes.rogue.battle.attack4;
		if (enemy[1].hp != 0)
			enemy[1].battle_sprite = enemy[1].get_damage;
		key_attack = 0;
		attack_rouge.Attack4(all_heroes.rogue, enemy[1]);
		return true;
	}
	return false;
}
bool AttackModeWizard(StructAllHeroes& all_heroes, StructEnemy enemy[4], int& key_attack)
{
	AttacksWizard attack_wizard;
	if (key_attack == 1)
	{
		all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.attack1;
		if (enemy[2].hp != 0)
			enemy[2].battle_sprite = enemy[2].get_damage;
		key_attack = 0;
		attack_wizard.Attack1(enemy[2]);
		return true;
	}
	else if (key_attack == 2)
	{
		all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.attack2;
		key_attack = 0;
		attack_wizard.Attack2(all_heroes);
		return true;
	}
	else if (key_attack == 3)
	{
		all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.attack3;
		key_attack = 0;
		attack_wizard.Attack3(all_heroes);
		return true;
	}
	else if (key_attack == 4)
	{
		all_heroes.wizard.battle.batle_sprite = all_heroes.wizard.battle.attack4;
		if (enemy[1].hp != 0)
			enemy[1].battle_sprite = enemy[1].get_damage;
		key_attack = 0;
		attack_wizard.Attack4(enemy[1]);
		return true;
	}
	return false;
}
bool AttackModeMage(StructAllHeroes& all_heroes, int& key_attack)
{
	AttacksMage attack_mage;
	if (key_attack == 1)
	{
		all_heroes.mage.battle.batle_sprite = all_heroes.mage.battle.attack1;
		key_attack = 0;
		attack_mage.Attack1(all_heroes);
		return true;
	}
	else if (key_attack == 2)
	{
		all_heroes.mage.battle.batle_sprite = all_heroes.mage.battle.attack2;
		key_attack = 0;
		attack_mage.Attack2(all_heroes);
		return true;
	}
	else if (key_attack == 3)
	{
		all_heroes.mage.battle.batle_sprite = all_heroes.mage.battle.attack3;
		key_attack = 0;
		attack_mage.Attack3(all_heroes);
		return true;
	}
	else if (key_attack == 4)
	{
		all_heroes.mage.battle.batle_sprite = all_heroes.mage.battle.attack4;
		key_attack = 0;
		attack_mage.Attack4(all_heroes);
		return true;
	}
	return false;
}

void DrawHeroes(StructAllHeroes all_heroes, RenderWindow& window)
{
	window.draw(all_heroes.cruasder.battle.stay);
	window.draw(all_heroes.rogue.battle.stay);
	window.draw(all_heroes.wizard.battle.stay);
	window.draw(all_heroes.mage.battle.stay);

	//window.draw(all_heroes.cruasder.battle.batle_sprite);
	//window.draw(all_heroes.rogue.battle.batle_sprite);
	//window.draw(all_heroes.wizard.battle.batle_sprite);
	//window.draw(all_heroes.mage.battle.batle_sprite);

}
void DrawEnemy(StructEnemy enemy[3], RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(enemy[i].stay);
	}
}
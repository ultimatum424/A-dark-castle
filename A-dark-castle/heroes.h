#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

struct StructEnemy
{
	RectangleShape sq;
	Sprite stay;
	Sprite attack;
	Sprite get_damage;
	Sprite die;
	int hp;
};
struct StructLocalEnemy
{
	StructEnemy enemy[3];
};
struct StructAllEnemy
{
	StructEnemy skeleton;
	StructEnemy ghost;
	StructEnemy alien;
};

struct Structheroes
{
	struct StructStast
	{
		int hp;
		int max_hp;
		float damage;
		float def;
		int position;
	} stats;
	struct StructBattle
	{
		Vector2f heroesPosition;
		struct StructAction
		{
			int pos_x;
			int pos_y;
			int size_x;
			int size_y;
		};
		Sprite stay;
		Sprite attack1;
		Sprite attack2;
		Sprite attack3;
		Sprite attack4;
		Sprite get_damage;
		Sprite die;

		Sprite batle_sprite;
		Sprite batle_icon;
		Sprite image_ability;
	} battle;
	struct StructExploration
	{
		Vector2f heroesPosition;
		struct StructMove
		{
			float num_frame;
			int pos_x;
			int pos_y;
			int size_x;
			int size_y;
		} move;
		Sprite sprite;
	} exploration;

};
struct StructAllHeroes
{
	Structheroes wizard;
	Structheroes rogue;
	Structheroes cruasder;
	Structheroes mage;
};




struct AttacksRogue
{
	void Attack1(Structheroes& rogue, StructEnemy& victim)
	{
		if (victim.hp >= 10) victim.hp -= 10;
		else victim.hp = 0;

	}
	void Attack2(Structheroes& rogue)
	{
		if (rogue.stats.damage <= 2) rogue.stats.damage = rogue.stats.damage + 0.5;
		else rogue.stats.damage = 2;

	}
	void Attack3(StructEnemy& victim, StructEnemy& victim2, StructEnemy& victim3)
	{
		if (victim.hp >= 5) victim.hp -= 5;
		else victim.hp = 0;
		if (victim2.hp >= 5) victim2.hp -= 5;
		else victim2.hp = 0;
		if (victim3.hp >= 5) victim3.hp -= 5;
		else victim3.hp = 0;
	}
	void Attack4(Structheroes& rogue, StructEnemy& victim)
	{
		if (victim.hp >= 20)
		{
			victim.hp -= 20;
			if (rogue.stats.damage > 0.2) rogue.stats.damage -= 0.2;
			else rogue.stats.damage = 0.1;
		}
		else
		{
			victim.hp = 0;
			if (rogue.stats.damage > 0.2) rogue.stats.damage -= 0.2;
			else rogue.stats.damage = 0.1;
		};
	}
};
struct AttacksCruasder
{
	void Attack1(Structheroes& cruasder, StructEnemy& victim)
	{
		if (victim.hp > 15) victim.hp -= 15;
		else victim.hp = 0;
	}
	void Attack2(Structheroes& cruasder)
	{
		cruasder.stats.def = cruasder.stats.def + 0.5;
	}
	void Attack3(Structheroes& cruasder)
	{
		if (cruasder.stats.hp <= (cruasder.stats.max_hp - 10)) cruasder.stats.hp += 10;
		else (cruasder.stats.hp = cruasder.stats.max_hp);
	}
	void Attack4(Structheroes& cruasder, StructEnemy& victim)
	{
		if (victim.hp >= 20)
		{
			victim.hp -= 20;
			if (cruasder.stats.def > 0.2) cruasder.stats.def -= 0.2;
			else cruasder.stats.def = 0.1;
		}
		else
		{
			victim.hp = 0;
			if (cruasder.stats.def > 0.2) cruasder.stats.def -= 0.2;
			else cruasder.stats.def = 0.1;
		}
	}
};
struct AttacksWizard
{
	void Attack1(StructEnemy& victim)
	{
		if (victim.hp >= 7) victim.hp -= 7;
		else victim.hp = 0;
	}
	void Attack2(StructAllHeroes& all_heroes)
	{
		all_heroes.wizard.stats.def = all_heroes.wizard.stats.def + 0.15;
		all_heroes.cruasder.stats.def = all_heroes.cruasder.stats.def + 0.15;
		all_heroes.rogue.stats.def = all_heroes.rogue.stats.def + 0.15;
		all_heroes.mage.stats.def = all_heroes.mage.stats.def + 0.15;
	}
	void Attack3(StructAllHeroes& all_heroes)
	{
		all_heroes.cruasder.stats.damage += 0.1;
		all_heroes.rogue.stats.damage += 0.1;
		all_heroes.wizard.stats.damage += 0.1;
		all_heroes.mage.stats.damage += 0.1;
	}
	void Attack4(StructEnemy& victim)
	{
		if (victim.hp >= 10) victim.hp -= 10;
		else victim.hp = 0;
	}
};
struct AttacksMage
{
	void Attack1(StructAllHeroes& all_heroes)
	{
		if (all_heroes.cruasder.stats.hp <= (all_heroes.cruasder.stats.max_hp) - 6) all_heroes.cruasder.stats.hp += 6;
		else all_heroes.cruasder.stats.hp = all_heroes.cruasder.stats.max_hp;
	}
	void Attack2(StructAllHeroes& all_heroes)
	{
		if (all_heroes.rogue.stats.hp <= (all_heroes.rogue.stats.max_hp) - 6) all_heroes.rogue.stats.hp += 6;
		else all_heroes.rogue.stats.hp = all_heroes.rogue.stats.max_hp;
	}
	void Attack3(StructAllHeroes& all_heroes)
	{
		if (all_heroes.wizard.stats.hp <= (all_heroes.wizard.stats.max_hp) - 6) all_heroes.wizard.stats.hp += 6;
		else all_heroes.wizard.stats.hp = all_heroes.wizard.stats.max_hp;
	}
	void Attack4(StructAllHeroes& all_heroes)
	{
		if (all_heroes.cruasder.stats.hp <= (all_heroes.cruasder.stats.max_hp) - 3) all_heroes.cruasder.stats.hp += 3;
		else all_heroes.cruasder.stats.hp = all_heroes.cruasder.stats.max_hp;
		if (all_heroes.rogue.stats.hp <= (all_heroes.rogue.stats.max_hp) - 3) all_heroes.rogue.stats.hp += 3;
		else all_heroes.rogue.stats.hp = all_heroes.rogue.stats.max_hp;
		if (all_heroes.wizard.stats.hp <= (all_heroes.wizard.stats.max_hp) - 3) all_heroes.wizard.stats.hp += 3;
		else all_heroes.wizard.stats.hp = all_heroes.wizard.stats.max_hp;
		if (all_heroes.mage.stats.hp <= (all_heroes.mage.stats.max_hp) - 3) all_heroes.mage.stats.hp += 3;
		else all_heroes.mage.stats.hp = all_heroes.mage.stats.max_hp;
	}
};


void InitHeroCrusader(Structheroes& hero, vector<string> file);
void InitHeroRogue(Structheroes& hero, vector<string> file);
void InitHeroWizard(Structheroes& hero, vector<string> file);
void InitHeroMage(Structheroes& hero, vector<string> file);
void InitHeroes(StructAllHeroes& all_heroes);
void InitSkeleton(StructEnemy& enemy, string file);
void InitAllEnemy(StructAllEnemy& all_enemy);
void InitLocalEnemy(StructAllEnemy& all_enemy, StructLocalEnemy local_enemy[5]);

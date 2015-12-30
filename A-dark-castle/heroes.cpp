#include "heroes.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace sf;
using namespace std;

void InitHeroCrusader(Structheroes& hero, vector<string> file)
{
	Image image;
	Texture texture;
	image.loadFromFile(file[0]);
	texture.loadFromImage(image);
	hero.battle.stay.setTexture(texture);
	hero.battle.stay.setTextureRect(IntRect(0, 1282, 180, 430));
	hero.battle.attack1.setTexture(texture);
	hero.battle.attack1.setTextureRect(IntRect(0, 0, 235, 340));
	hero.battle.attack2.setTexture(texture);
	hero.battle.attack2.setTextureRect(IntRect(0, 340, 453, 233));
	hero.battle.attack3.setTexture(texture);
	hero.battle.attack3.setTextureRect(IntRect(0, 573, 267, 384));
	hero.battle.attack4.setTexture(texture);
	hero.battle.attack4.setTextureRect(IntRect(0, 957, 287, 325));
	image.loadFromFile(file[1]);
	texture.loadFromImage(image);
	hero.battle.batle_icon.setTexture(texture);
	hero.stats.max_hp = hero.stats.hp = 60;
	hero.stats.def = 1;
	hero.stats.damage = 0.5;
}
void InitHeroRogue(Structheroes& hero, vector<string> file)
{
	Image image;
	Texture texture;
	image.loadFromFile(file[0]);
	texture.loadFromImage(image);

	hero.battle.stay.setTexture(texture);
	hero.battle.stay.setTextureRect(IntRect(0, 1282, 180, 430));
	hero.battle.attack1.setTexture(texture);
	hero.battle.attack1.setTextureRect(IntRect(0, 0, 235, 340));
	hero.battle.attack2.setTexture(texture);
	hero.battle.attack2.setTextureRect(IntRect(0, 340, 453, 233));
	hero.battle.attack3.setTexture(texture);
	hero.battle.attack3.setTextureRect(IntRect(0, 573, 267, 384));
	hero.battle.attack4.setTexture(texture);
	hero.battle.attack4.setTextureRect(IntRect(0, 957, 287, 325));

	image.loadFromFile(file[1]);
	texture.loadFromImage(image);
	hero.battle.batle_icon.setTexture(texture);
	hero.stats.max_hp = hero.stats.hp = 40;
	hero.stats.def = 0.25;
	hero.stats.damage = 1.5;
}
void InitHeroWizard(Structheroes& hero, vector<string> file)
{
	Image image;
	Texture texture;
	image.loadFromFile(file[0]);
	texture.loadFromImage(image);

	hero.battle.stay.setTexture(texture);
	hero.battle.stay.setTextureRect(IntRect(0, 1282, 180, 430));
	hero.battle.attack1.setTexture(texture);
	hero.battle.attack1.setTextureRect(IntRect(0, 0, 235, 340));
	hero.battle.attack2.setTexture(texture);
	hero.battle.attack2.setTextureRect(IntRect(0, 340, 453, 233));
	hero.battle.attack3.setTexture(texture);
	hero.battle.attack3.setTextureRect(IntRect(0, 573, 267, 384));
	hero.battle.attack4.setTexture(texture);
	hero.battle.attack4.setTextureRect(IntRect(0, 957, 287, 325));

	image.loadFromFile(file[1]);
	texture.loadFromImage(image);
	hero.battle.batle_icon.setTexture(texture);
	hero.stats.max_hp = hero.stats.hp = 30;
	hero.stats.def = 0.5;
	hero.stats.damage = 0.5;
}
void InitHeroMage(Structheroes& hero, vector<string> file)
{
	Image image;
	Texture texture;
	image.loadFromFile(file[0]);
	texture.loadFromImage(image);

	hero.battle.stay.setTexture(texture);
	hero.battle.stay.setTextureRect(IntRect(0, 1282, 180, 430));
	hero.battle.attack1.setTexture(texture);
	hero.battle.attack1.setTextureRect(IntRect(0, 0, 235, 340));
	hero.battle.attack2.setTexture(texture);
	hero.battle.attack2.setTextureRect(IntRect(0, 340, 453, 233));
	hero.battle.attack3.setTexture(texture);
	hero.battle.attack3.setTextureRect(IntRect(0, 573, 267, 384));
	hero.battle.attack4.setTexture(texture);
	hero.battle.attack4.setTextureRect(IntRect(0, 957, 287, 325));

	image.loadFromFile(file[1]);
	texture.loadFromImage(image);
	hero.battle.batle_icon.setTexture(texture);
	hero.stats.max_hp = hero.stats.hp = 30;
	hero.stats.def = 0.5;
	hero.stats.damage = 0.5;
}

void InitHeroes(StructAllHeroes& all_heroes)
{
	vector<string> files = { "../images/heroes/crusader/attack.png", "../images/heroes/crusader/icon.png" };
	InitHeroCrusader(all_heroes.cruasder, files);
	files = { "../images/heroes/crusader/attack.png", "../images/heroes/crusader/icon.png" };
	InitHeroRogue(all_heroes.cruasder, files);
	files = { "../images/heroes/crusader/attack.png", "../images/heroes/crusader/icon.png" };
	InitHeroWizard(all_heroes.cruasder, files);
	files = { "../images/heroes/crusader/attack.png", "../images/heroes/crusader/icon.png" };
	InitHeroMage(all_heroes.cruasder, files);
}

void InitSkeleton(StructEnemy& enemy, string file)
{
	Image image;
	Texture texture;
	image.loadFromFile(file);
	texture.loadFromImage(image);

	enemy.stay.setTexture(texture);
	enemy.stay.setTextureRect(IntRect(0, 0, 200, 282));
	enemy.attack.setTexture(texture);
	enemy.attack.setTextureRect(IntRect(0, 282, 336, 287));
	enemy.get_damage.setTexture(texture);
	enemy.get_damage.setTextureRect(IntRect(0, 569, 181, 289));
}
void InitAllEnemy(StructAllEnemy& all_enemy)
{
	InitSkeleton(all_enemy.skeleton, "../images/enemy/skeleton/skeleton.png");
}
void InitLocalEnemy(StructAllEnemy& all_enemy, StructLocalEnemy local_enemy[4])
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int secret = rand() % 5;
			std::cout << i << "---" << secret << "--" << j << "\n";
			if (secret == 0) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 1) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 2) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 3) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 4) local_enemy[i].enemy[j] = all_enemy.skeleton;
		}
	}
}
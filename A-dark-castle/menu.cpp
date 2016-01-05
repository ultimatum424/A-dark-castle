#pragma once
#include "menu.h"
#include "event.h"
#include <iostream>
void LoadSprite(StructMenu menu)
{

}

void InitMenu(StructMenu& menu)
{
	menu.flag.level = 0;
	menu.flag.menu_item = 0;

	menu.background.image.loadFromFile("../images/menu/background.png");
	menu.background.texture.loadFromImage(menu.background.image);
	menu.background.sprite.setTexture(menu.background.texture);
	//menu.background.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.city.image.loadFromFile("../images/menu/�ity.png");
	menu.city.texture.loadFromImage(menu.city.image);
	menu.city.sprite.setTexture(menu.city.texture);
	//menu.city.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.castle.image.loadFromFile("../images/menu/castle.png");
	menu.castle.texture.loadFromImage(menu.castle.image);
	menu.castle.sprite.setTexture(menu.castle.texture);
	//menu.castle.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.font.loadFromFile("../Fonts/9210.ttf");
	menu.level.setFont(menu.font);
	menu.level.setCharacterSize(40);
	menu.level.setColor(Color::White);
	menu.level.setString(L"����� ������");
	//menu.level.setPosition(view_�entre.x + 300, view_�entre.y - 250);
	
	menu.shop.setFont(menu.font);
	menu.shop.setCharacterSize(40);
	menu.shop.setColor(Color::White);
	menu.shop.setString(L"�������");
	//menu.shop.setPosition(view_�entre.x + 0, view_�entre.y - 0);

	menu.exit.setFont(menu.font);
	menu.exit.setCharacterSize(40);
	menu.exit.setColor(Color::White);
	menu.exit.setString(L"�����");
	//menu.exit.setPosition(view_�entre.x , view_�entre.y + 250);

}
void UpdateMenu(StructMenu& menu, StructEvent key_event, int& stage_game, Vector2f view_�entre)
{
	menu.background.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));
	menu.city.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));
	menu.castle.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));
	menu.level.setPosition(view_�entre.x + 300, view_�entre.y - 250);
	menu.shop.setPosition(view_�entre.x + 0, view_�entre.y - 0);
	menu.exit.setPosition(view_�entre.x, view_�entre.y + 250);
	if ((key_event.key_up == 1) && (menu.flag.menu_item < 2))
		menu.flag.menu_item++;
	else if ((key_event.key_down == 1) && (menu.flag.menu_item > 0))
		menu.flag.menu_item--;
	if (menu.flag.menu_item == 2)
		menu.level.setColor(Color::Red);
	else
		menu.level.setColor(Color::White);
	if (menu.flag.menu_item == 1)
		menu.shop.setColor(Color::Red);
	else
		menu.shop.setColor(Color::White);
	if (menu.flag.menu_item == 0)
		menu.exit.setColor(Color::Red);
	else
		menu.exit.setColor(Color::White);
	if ((menu.flag.menu_item == 2) && (key_event.key_space == 1))
		stage_game = 1;
	if ((menu.flag.menu_item == 1) && (key_event.key_space == 1))
		menu.flag.level = 1;

}

void DrawMenu(StructMenu menu, RenderWindow& window)
{
	if (menu.flag.level == 0)
		window.draw(menu.city.sprite);
	else if (menu.flag.level == 1)
		window.draw(menu.castle.sprite);
	window.draw(menu.level);
	window.draw(menu.shop);
	window.draw(menu.exit);
}
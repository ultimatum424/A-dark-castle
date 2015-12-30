#pragma once
#include "menu.h"
//#include "event.h"
void LoadSprite(StructMenu menu)
{

}

void InitMenu(StructMenu& menu, Vector2f view_�entre)
{
	menu.flag.level = 0;

	menu.background.image.loadFromFile("../images/menu/background.png");
	menu.background.texture.loadFromImage(menu.background.image);
	menu.background.sprite.setTexture(menu.background.texture);
	menu.background.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.city.image.loadFromFile("../images/menu/�ity.png");
	menu.city.texture.loadFromImage(menu.city.image);
	menu.city.sprite.setTexture(menu.city.texture);
	menu.city.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.castle.image.loadFromFile("../images/menu/castle.png");
	menu.castle.texture.loadFromImage(menu.castle.image);
	menu.castle.sprite.setTexture(menu.castle.texture);
	menu.castle.sprite.setPosition((view_�entre.x - view_�entre.x), (view_�entre.y - view_�entre.y));

	menu.font.loadFromFile("../Fonts/9210.ttf");
	menu.text_castle.setFont(menu.font);
	menu.text_castle.setCharacterSize(40);
	menu.text_castle.setColor(Color::White);
	menu.text_castle.setString(L"����� ������");
	menu.text_castle.setPosition(view_�entre.x + 300, view_�entre.y - 250);

}
void UpdateMenu(StructMenu& menu)
{
	menu.flag.menu_item = 1;
	/*if ((key_event.key_up == 1) && (menu.flag.menu_item < 2))
		menu.flag.menu_item++;
	else if ((key_event.key_down == 1) && (menu.flag.menu_item > 0))
		menu.flag.menu_item--;*/
	if (menu.flag.menu_item == 2)
		menu.text_castle.setColor(Color::Red);
	else
		menu.text_castle.setColor(Color::White);
}

void DrawMenu(StructMenu menu, RenderWindow& window)
{
	menu.flag.level = 0;
	if (menu.flag.level == 0)
		window.draw(menu.city.sprite);
	else if (menu.flag.level == 1)
		window.draw(menu.castle.sprite);
	window.draw(menu.text_castle);
}
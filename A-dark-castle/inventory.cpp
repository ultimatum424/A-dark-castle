#include "inventory.h"
#include <iostream>
#include "event.h"

void InitInventoryElement(StructInventory::StructCellInventory& element, Texture& texture, Font& font)
{
	element.sprite.setTexture(texture);
	element.size = { 72, 144 };
	element.text.setFont(font);
	element.text.setCharacterSize(25);
	element.quantity = QUANTITY;
}
void InitInventory(StructInventory& inventory)
{
	inventory.image.image.loadFromFile("../images/exploration/inventory.png");
	inventory.image.texture.loadFromImage(inventory.image.image);
	inventory.font.loadFromFile("../Fonts/9210.ttf");
	InitInventoryElement(inventory.food, inventory.image.texture, inventory.font);
	InitInventoryElement(inventory.gold, inventory.image.texture, inventory.font);
	InitInventoryElement(inventory.relics, inventory.image.texture, inventory.font);
	
}
void InitShop(StructInventory& inventory)
{
	inventory.image_shop.image.loadFromFile("../images/exploration/shop-background.png");
	inventory.image_shop.texture.loadFromImage(inventory.image_shop.image);
	inventory.shop.shop_background.setTexture(inventory.image_shop.texture);
	inventory.shop.food_gold.setFont(inventory.font);
	inventory.shop.relics_gold.setFont(inventory.font);
	inventory.shop.relics_gold.setCharacterSize(25);
	inventory.shop.food_gold.setCharacterSize(25);
	inventory.shop.food_gold.setString(L"������ ������ ���");
	inventory.shop.relics_gold.setString(L"������� ��������");
}

void UpdeatInventory(StructInventory& inventory, Vector2f view_�entre)
{
	inventory.food.sprite.setTextureRect(IntRect(0, 0, inventory.food.size.x, inventory.food.size.y));
	inventory.gold.sprite.setTextureRect(IntRect(inventory.food.size.x, 0, inventory.food.size.x, inventory.food.size.y));
	inventory.relics.sprite.setTextureRect(IntRect(inventory.food.size.x * 2, 0, inventory.food.size.x, inventory.food.size.y));

	inventory.food.sprite.setPosition(view_�entre.x + 400, view_�entre.y + 200);
	inventory.gold.sprite.setPosition(view_�entre.x + 400 + inventory.gold.size.x, view_�entre.y + 200);
	inventory.relics.sprite.setPosition(view_�entre.x + 400 + (inventory.relics.size.x * 2), view_�entre.y + 200);

	std::ostringstream temp_food;
	std::ostringstream temp_gold;
	std::ostringstream temp_relics;

	temp_food << inventory.food.quantity;
	temp_gold << inventory.gold.quantity;
	temp_relics << inventory.relics.quantity;

	inventory.food.text.setString(temp_food.str());
	inventory.gold.text.setString(temp_gold.str());
	inventory.relics.text.setString(temp_relics.str());

	inventory.food.text.setPosition(view_�entre.x + 410 + inventory.gold.size.x, view_�entre.y + 200);
	inventory.gold.text.setPosition(view_�entre.x + 410 , view_�entre.y + 200);
	inventory.relics.text.setPosition(view_�entre.x + 410 + (inventory.relics.size.x * 2), view_�entre.y + 200);
}
void DrawInventory(StructInventory& inventory, RenderWindow& window)
{
	window.draw(inventory.food.sprite);
	window.draw(inventory.gold.sprite);
	window.draw(inventory.relics.sprite);
	window.draw(inventory.gold.text);
	window.draw(inventory.food.text);
	window.draw(inventory.relics.text);
}
void UpdeatShop(StructInventory& inventory, Vector2f view_�entre)
{
	inventory.shop.shop_background.setPosition(view_�entre.x - 700, view_�entre.y - 400);
	inventory.shop.food_gold.setPosition(view_�entre.x + 300, view_�entre.y - 350);
	inventory.shop.relics_gold.setPosition(view_�entre.x + 300, view_�entre.y - 50);
	if (inventory.shop.shop_cell == 1)
	{
		inventory.shop.food_gold.setColor(Color::Red);
		inventory.shop.relics_gold.setColor(Color::White);
	}
	if (inventory.shop.shop_cell == 2)
	{
		inventory.shop.food_gold.setColor(Color::White);
		inventory.shop.relics_gold.setColor(Color::Red);
	}
}
void DrawShop(StructInventory& inventory, RenderWindow& window)
{
	window.draw(inventory.shop.shop_background);
	window.draw(inventory.shop.food_gold);
	window.draw(inventory.shop.relics_gold);
	DrawInventory(inventory, window);
}
void ShopMode(StructInventory& inventory, StructEvent key_event, Vector2f view_�entre, int& stage_game)
{
	UpdeatShop(inventory, view_�entre);
	UpdeatInventory(inventory, view_�entre);
	if (key_event.key_up)
		inventory.shop.shop_cell = 1;
	if (key_event.key_down)
		inventory.shop.shop_cell = 2;
	if (key_event.key_space)
	{
		if (inventory.shop.shop_cell == 2)
		{
			if (inventory.relics.quantity)
			{
				inventory.relics.quantity--;
				inventory.gold.quantity += 100;
			}
		}
		if (inventory.shop.shop_cell == 1)
		{
			if ((inventory.gold.quantity / 50) >= 1)
			{
				inventory.gold.quantity -= 50;
				inventory.food.quantity++;
			}
		}
	}
	if (key_event.key_escape)
		stage_game = 1;
}

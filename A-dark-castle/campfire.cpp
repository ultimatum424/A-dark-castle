#include "campfire.h"


void InitCampfire(StructCampfire& campfire)
{
	campfire.camp_image.image.loadFromFile("../images/campfire/campfire.png");
	campfire.camp_image.texture.loadFromImage(campfire.camp_image.image);
	campfire.camp_image.sprite.setTexture(campfire.camp_image.texture);
}
void UpdateCampfire(StructCampfire& campfire, Vector2f view_ñentre)
{
	campfire.camp_image.sprite.setPosition(view_ñentre.x - 700, view_ñentre.y - 400);
}
void CampfireMod(StructAllHeroes& all_heroes, StructInventory& inventory, StructEvent key_event)
{
	if ((key_event.key_attack == 1) && (inventory.food.quantity > 10))
	{
		all_heroes.cruasder.stats.hp = all_heroes.cruasder.stats.max_hp;
		all_heroes.rogue.stats.hp = all_heroes.cruasder.stats.max_hp;
		all_heroes.wizard.stats.hp = all_heroes.cruasder.stats.max_hp;
		all_heroes.mage.stats.hp = all_heroes.cruasder.stats.max_hp;
		inventory.food.quantity -= 10;
	}
	if ((key_event.key_attack == 2) && (inventory.food.quantity > 5))
	{
		all_heroes.cruasder.stats.def += 0.5;
		all_heroes.rogue.stats.def += 0.5;
		all_heroes.wizard.stats.def += 0.5;
		all_heroes.mage.stats.def += 0.5;
		inventory.food.quantity -= 5;
	}
	if ((key_event.key_attack == 3) && (inventory.food.quantity > 10))
	{
		all_heroes.cruasder.stats.damage += 0.5;
		all_heroes.rogue.stats.damage += 0.5;
		all_heroes.wizard.stats.damage += 0.5;
		all_heroes.mage.stats.damage += 0.5;
		inventory.food.quantity -= 10;
	}
}
void DrawCampfire(StructCampfire& campfire, StructInventory& inventory, RenderWindow& window)
{
	window.draw(campfire.camp_image.sprite);
	DrawInventory(inventory, window);
}
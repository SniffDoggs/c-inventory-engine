#include <stdio.h>
#include "inventory.h"

/* inspect category of item and print its properties accordingly */
void inspect_item(item *item_ptr)
{
	if (item_ptr->category == ITEM_WEAPON) {
		printf("Damage Points: %d\n", item_ptr->data.weapon.damage_points);
	} else if (item_ptr->category == ITEM_POTION) {
		printf("Healing Points: %d\n", item_ptr->data.potion.healing_points);
	}
}

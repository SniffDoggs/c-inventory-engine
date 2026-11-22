#include <stdio.h>
#include "inventory.h"

/* inspect category of item and print its properties accordingly */
void print_item_by_type(item *item_ptr, size_t item_index)
{
	if (item_ptr->category == ITEM_WEAPON) {
		printf("*********************************************************************************\n"
			   "Weapon at slot #%d deals: %d hp\n", (int)item_index, item_ptr->data.weapon.damage_points);
	} else if (item_ptr->category == ITEM_POTION) {
		printf("*********************************************************************************\n"
			   "Potion at slot #%d heals: %d hp\n", (int)item_index, item_ptr->data.potion.healing_points);
	}
}

item *add_item(item *inventory, size_t inventory_size, size_t slot_index, item new_item, size_t *empty_slots)
{
	if (slot_index >= inventory_size) {
		return inventory;
	}

	if (inventory[slot_index].category == 0) {
		(*empty_slots)--;
	}
	inventory[slot_index] = new_item;

	return inventory;
}

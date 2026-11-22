#include <stdio.h>
#include "inventory.h"

item *prompt_add_item(item *inventory, size_t inventory_size, size_t *empty_slots)
{
	item new_item;
	size_t slot;

	do {
		printf("*********************************************************************************\n"
			   "There are %zu available slots,\n"
			   "Which slot do you want to add your item in? ", *empty_slots);
		scanf("%zu", &slot);

		if (!(slot >= 1 && slot <= inventory_size)) {
			printf("*********************************************************************************\n"
				   "Invalid input: please enter a slot number that is less than your inventory size\n");
			}

		} while (!(slot >= 1 && slot <= inventory_size));

	i32 item_choice;

	do {

		printf("*********************************************************************************\n"
			   "What do you want your item to be?\n\n"
			   "Press 1 for weapon\n"
			   "Press 2 for potion\n"
			   "\n"
			   "Enter your choice: ");
		scanf("%d", &item_choice);

		switch (item_choice) {
		case 1:
			new_item.category = ITEM_WEAPON;

			printf("*********************************************************************************\n"
				   "How much damage will your weapon deal(1-100 hp)? ");
			scanf("%hd", &new_item.data.weapon.damage_points);

			break;
		case 2:
			new_item.category = ITEM_POTION;

			printf("*********************************************************************************\n"
				   "How much health will your potion regenerate(1-100 HP)? ");
			scanf("%hd", &new_item.data.potion.healing_points);

			break;
		} ;
	}  while (!(item_choice >= 1 && item_choice <= 2));

	size_t slot_index = slot - 1;

	return add_item(inventory, inventory_size, slot_index, new_item, empty_slots);
}

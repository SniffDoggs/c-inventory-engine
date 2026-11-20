#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"

// inspect category of item and print its properties accordingly

void inspect_item(Item *item_ptr)
{
	if (item_ptr->category == WEAPON) {
		printf("Damage Points: %d\n", item_ptr->data.weapon.damage_points);
	} else if (item_ptr->category == POTION) {
		printf("Healing Points: %d\n", item_ptr->data.potion.healing_points);
	}
}

int main()
{
	Item *inventory = NULL;
	size_t inventory_size = 0;

	printf("Enter the number of slots: ");
	scanf("%ld", &inventory_size);

	inventory = calloc(inventory_size, sizeof(*inventory));

	if (inventory == NULL) {
		fprintf(stderr, "Error: Memory allocation failed.\n");
	return 1;
	}

	size_t empty_slots = 0;
	
	do {
		for (size_t i = 0; i < inventory_size; ++i) {
			if (inventory[i] != 0) {
				++empty_slots;
			}
		}

		i32 choice;
		printf("Choose an option: \n"
		"Press 1 to add an item,\n"
		"Press 2 to delete an item,\n"
		"Press 3 to see items.\n"
		"Press 4 to exit\n"
		"\n"
		"Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch (choice) {
		case 1: { 
			i32 slot;

			do {
				printf("There are %zu available slots,\n"
				"Which slot do you want to add your item in? ", empty_slots);
				scanf("%d", &slot);

				if (!(slot >= 1 && slot <= inventory_size)) {
					printf("Invalid input: please enter a slot number that is less than your inventory size");
				}
				
			} while (!(slot >= 1 && slot <= inventory_size));

			i32 item_choice;

			do {

				printf("What do you want your item to be?\n"
				       "Press 1 for weapon\n"
				       "Press 2 for potion\n"
				       "\n"
				       "Enter your choice: ");
				scanf("%d", &item_choice);

				switch (item_choice) {
				case 1:
					inventory[slot - 1].category = WEAPON;

					printf("How much damage will your weapon deal(1-100 hp)? ");
					scanf("%d", &inventory[slot - 1].data.weapon.damage_points);

					break;
				case 2:
					inventory[slot - 1].category = POTION;

					printf("How much health will your potion regenerate(1-100 HP)? ");
					scanf("%d", &inventory[slot - 1].data.potion.healing_points);

					break;
				} while (!(item_choice >= 1 && item_choice <= 100);

			}
		}

	} while (1); 

	inventory[0].category = WEAPON;
	inventory[0].data.weapon.damage_points = 30;

	inventory[1].category = POTION;
	inventory[1].data.potion.healing_points = 50;

	for (size_t i = 0; i < 2; i++) {
		inspect_item(&inventory[i]);
	}

	printf("%zu\n", inventory_size);

	free(inventory);
}



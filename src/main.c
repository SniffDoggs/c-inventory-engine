#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "inventory.h"

int main()
{
	item *inventory = NULL;
	size_t inventory_size = 0;

	printf("*********************************************************************************\n");
	printf("Enter the number of slots: ");
	scanf("%ld", &inventory_size);

	inventory = calloc(inventory_size, sizeof(*inventory));

	if (inventory == NULL) {
		fprintf(stderr, "Error: Memory allocation failed.\n");
	return 1;
	}

	size_t empty_slots = inventory_size;
	
	bool input_loop_is_running = true;
	do {
		i32 choice;
		printf("*********************************************************************************\n"
		       "Choose an option: \n"
		       "Press 1 to add an item,\n"
		       "Press 2 to delete an item,\n"
		       "Press 3 to see items.\n"
		       "Press 4 to exit\n"
		       "Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:  
			inventory = prompt_add_item(inventory, inventory_size, &empty_slots);
			break;
		case 3:
			for (size_t i = 0; i < inventory_size ; ++i) {
				print_item_by_type(&inventory[i], i + 1);
			}
			break;
		case 4:
			printf("*********************************************************************************\n"
				   "Exiting...\n"
				   "Thanks for playing!\n"
				   "*********************************************************************************\n");	
			input_loop_is_running = false;
		}

	} while (input_loop_is_running); 

	free(inventory);
}



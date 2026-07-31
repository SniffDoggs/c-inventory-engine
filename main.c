#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"

// inspect category of item and print its properties accordingly

void inspect_item(Item *item_ptr){
    if (item_ptr->category == WEAPON) {
        printf("Damage Points: %d\n", item_ptr->data.weapon.damage_points);
    } else if (item_ptr->category == POTION) {
        printf("Healing Points: %d\n", item_ptr->data.potion.healing_points);
    }
}

int main(){
    Item *inventory = NULL;
    i16 inventory_size = 0;

    printf("Enter the number of slots: ");
    scanf("%hd", &inventory_size);

    inventory = malloc(inventory_size * sizeof *inventory);

    if (inventory == NULL){
        fprintf(stderr, "Error: Memory allocation failed.\n");
    }

    inventory[0].category = WEAPON;
    inventory[0].data.weapon.damage_points = 30;

    inventory[1].category = POTION;
    inventory[1].data.potion.healing_points = 50;

    for (i8 i = 0; i < 2; i++){
        inspect_item(&inventory[i]);
    }

    free(inventory);
}



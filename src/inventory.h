#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

/* Values starting from 1 are assigned to make taking user input easier */
typedef enum {
    ITEM_WEAPON = 1,
    ITEM_POTION = 2,
    ITEM_KEY = 3,
} item_category;

typedef struct {
    u16 damage_points; 
} weapon_stats;

typedef struct {
    u16 healing_points; 
} potion_stats;

typedef union {
    weapon_stats weapon;
    potion_stats potion;
} item_data;

typedef struct {
    char name[32];
    item_category category;
    item_data data;
} item;

/* Inspects the item and prints its properties accordingly */
void print_item_by_type(item *item_ptr, size_t item_index);

/* Adds a new item to the given slot_index; returns inventory unchanged if out of bounds */
item *add_item(item *inventory, size_t inventory_size, size_t slot_index, item new_item, size_t *empty_slots);

/* Adds prompts to add_item function */
item *prompt_add_item(item *inventory, size_t inventory_size, size_t *empty_slots);

#endif

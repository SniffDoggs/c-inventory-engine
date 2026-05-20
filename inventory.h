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
typedef double d64;

// track categories of items in the game

typedef enum {
    WEAPON,
    POTION,
    KEY,
} ItemCategory;

// track properties of item types

typedef struct {
    u16 damage_points; // raw damage dealt per hit
} WeaponStats;

typedef struct {
    u16 healing_points; // health regenerated instantly
} PotionStats;

typedef union {
    WeaponStats weapon;
    PotionStats potion;
} ItemData;

// track item data

typedef struct {
    char name[32];
    ItemCategory category;
    ItemData data;
} Item;

void inspect_item(Item *item_ptr);

#endif

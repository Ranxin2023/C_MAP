#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct _PAIR
{
    int key;
    int value;
} PAIR;

typedef struct FREQUENCY_MAP
{
    size_t size;
    PAIR *key_values;
} F_MAP;

F_MAP *initialize()
{
    F_MAP *map = malloc(sizeof(F_MAP));
    map->size = 0;
    return map;
}

int find()
{
}
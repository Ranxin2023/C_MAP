#ifndef C_FREQUENCY_MAP_H
#define C_FREQUENCY_MAP_H
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
    PAIR **key_values;
} F_MAP;

PAIR *make_pair(int k, int v);
int int_key_compare(const void *a, const void *b);
void sort(F_MAP *m);
F_MAP *initialize();
void append(F_MAP *m, int key, int value);
int find(F_MAP *m, int key);
void update(F_MAP *m, int key, int value);
int get(F_MAP *m, int *find_flag, int key);
int get_or_default(F_MAP *m, int key, int value);
void print_map(F_MAP *m);
void free_map(F_MAP *m);
#endif
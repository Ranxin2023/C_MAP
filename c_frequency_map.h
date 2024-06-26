#ifndef C_FREQUENCY_MAP_H
#define C_FREQUENCY_MAP_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _INT_PAIR
{
    int key;
    int value;
} INT_PAIR;

typedef struct FREQUENCY_MAP
{
    size_t size;
    INT_PAIR **key_values;
} F_MAP;

INT_PAIR *make_int_pair(int k, int v);
int int_key_compare(const void *a, const void *b);
void sort_int_map(F_MAP *m);
F_MAP *initialize_int_map();
void append_int_map(F_MAP *m, int key, int value);
int find(F_MAP *m, int key);
void update_int_map(F_MAP *m, int key, int value);
int get(F_MAP *m, int *find_flag, int key);
int get_or_default(F_MAP *m, int key, int value);
void print_int_map(F_MAP *m);
void free_int_map(F_MAP *m);
#endif
#ifndef C_STRING_MAP_H
#define C_STRING_MAP_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _STRING_PAIR
{
    char *key;
    int value;
} STRING_PAIR;
typedef struct _STRING_MAP
{
    size_t size;
    STRING_PAIR **key_values;
} STRING_MAP;

STRING_PAIR *make_string_pair(char *key, int value);
int string_key_compare(const void *a, const void *b);
STRING_MAP *initialize_string_map();
void append_string_map(STRING_MAP *m, char *key, int value);
void sort_string_map(STRING_MAP *m);
int find_in_string_map(STRING_MAP *m, char *key);
void update_string_map(STRING_MAP *m, char *key, int value);
int get_from_string_map(STRING_MAP *m, int *find_flag, char *key);
int get_or_default_string_map(STRING_MAP *m, char *key, int default_value);
void print_string_map(STRING_MAP *m);
void free_string_map(STRING_MAP *m);
#endif
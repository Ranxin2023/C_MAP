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

} STRING_MAP;

STRING_PAIR *make_string_pair(char *key, int value);

#endif
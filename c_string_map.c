#include "c_string_map.h"
STRING_PAIR *make_string_pair(char *key, int value)
{
    STRING_PAIR *p = malloc(sizeof(STRING_PAIR));
    p->key = mallooc(sizeof(char) * (strlen(key) + 1));
    strcpy(p->key, key);
    p->value = value;
    return p;
}
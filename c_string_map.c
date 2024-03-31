#include "c_string_map.h"
STRING_PAIR *make_string_pair(char *key, int value)
{
    STRING_PAIR *p = malloc(sizeof(STRING_PAIR));
    p->key = mallooc(sizeof(char) * (strlen(key) + 1));
    strcpy(p->key, key);
    p->value = value;
    return p;
}

int string_key_compare(const void *a, const void *b)
{
    STRING_PAIR *p1 = *(STRING_PAIR **)a;
    STRING_PAIR *p2 = *(STRING_PAIR **)b;
    return strcmp(p1->key, p2->key);
}

STRING_MAP *initialize_string_map()
{
    STRING_MAP *sm = malloc(sizeof(STRING_MAP));
    sm->size = 0;
    sm->key_values = NULL;
    return sm;
}

void append_string_map(STRING_MAP *m, char *key, int value)
{
    if (find_in_string_map(m, key, value))
    {
        update_string_map(m, key, value);
        return;
    }
    m->key_values = (STRING_PAIR **)realloc(m->key_values, sizeof(STRING_PAIR *) * (m->size + 1));
    m->key_values[m->size] = make_string_pair(key, value);
    m->size += 1;
    sort_string_map(m);
}

void sort_string_map(STRING_MAP *m)
{
    qsort(m->key_values, m->size, sizeof(STRING_PAIR *), string_key_compare);
}
void update_string_map(STRING_MAP *m, char *key, int value)
{
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (strcmp(m->key_values[mid]->key, key) == 0)
        {
            m->key_values[mid]->value = value;
            return;
        }
        if (strcmp(m->key_values[mid]->key, key) < 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}
int find_in_string_map(STRING_MAP *m, char *key, int value)
{
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (strcmp(m->key_values[mid]->key, key) == 0)
        {
            return 1;
        }
        if (strcmp(m->key_values[mid]->key, key) < 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return 0;
}
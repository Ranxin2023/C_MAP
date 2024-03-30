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

PAIR *make_pair(int k, int v)
{
    PAIR *p = malloc(sizeof(PAIR));
    p->key = k;
    p->value = v;
    return p;
}
int compare(const void *a, const void *b)
{
    PAIR *p1 = (PAIR *)a;
    PAIR *p2 = (PAIR *)b;
    return p1->key - p2->key;
}

void sort(F_MAP *m)
{
    qsort(m->key_values, m->size, sizeof(PAIR), compare);
}

F_MAP *initialize()
{
    F_MAP *map = malloc(sizeof(F_MAP));
    map->size = 0;
    return map;
}

void append(F_MAP *m, int key, int value)
{
    if (find(m, key))
    {
        return;
    }
    m->key_values = (PAIR *)realloc(m->key_values, sizeof(PAIR) * (m->size + 1));
    m->key_values = make_pair(key, value);
    m->size += 1;
}
int find(F_MAP *m, int key)
{
    sort(m);
    int l = 0, r = m->size - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (m->key_values[mid].key == key)
        {
            return 1;
        }
        if (m->key_values[mid].key < key)
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

int main()
{
    return 0;
}
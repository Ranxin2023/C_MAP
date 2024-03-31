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

PAIR *make_pair(int k, int v)
{
    PAIR *p = malloc(sizeof(PAIR));
    p->key = k;
    p->value = v;
    return p;
}

int find(F_MAP *m, int key);
void update(F_MAP *m, int key, int value);
int compare(const void *a, const void *b)
{
    PAIR *p1 = *(PAIR **)a;
    PAIR *p2 = *(PAIR **)b;
    return p1->key - p2->key;
}

void sort(F_MAP *m)
{
    qsort(m->key_values, m->size, sizeof(PAIR *), compare);
}

F_MAP *initialize()
{
    F_MAP *map = malloc(sizeof(F_MAP));
    map->size = 0;
    map->key_values = NULL;
    return map;
}

void append(F_MAP *m, int key, int value)
{
    if (find(m, key))
    {
        update(m, key, value);
        return;
    }
    if (m->size == 0)
    {
        m->key_values = malloc(sizeof(PAIR *));
    }
    else
    {

        m->key_values = (PAIR **)realloc(m->key_values, sizeof(PAIR *) * (m->size + 1));
    }
    m->key_values[m->size] = make_pair(key, value);
    m->size += 1;
    sort(m);
}
int find(F_MAP *m, int key)
{
    // sort(m);
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (m->key_values[mid]->key == key)
        {
            return 1;
        }
        if (m->key_values[mid]->key < key)
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

void update(F_MAP *m, int key, int value)
{
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (m->key_values[mid]->key == key)
        {
            m->key_values[mid]->value = value;
            return;
        }
        if (m->key_values[mid]->key < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}
int get(F_MAP *m, int *find_flag, int key)
{
    if (!find(m, key))
    {
        *find_flag = 0;
        return -1;
    }
    *find_flag = 1;
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (m->key_values[mid]->key == key)
        {
            return m->key_values[mid]->value;
        }
        if (m->key_values[mid]->key < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    // this will never execute
    return 0;
}

int get_or_default(F_MAP *m, int key, int value)
{
    if (!find(m, key))
    {
        return value;
    }
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (m->key_values[mid]->key == key)
        {
            return m->key_values[mid]->value;
        }
        if (m->key_values[mid]->key < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    // this will never execute
    return 0;
}

void print_map(F_MAP *m)
{
    printf("All key value pairs in map are:\n");
    for (size_t i = 0; i < m->size; i++)
    {
        printf("num: %d, frequency: %d\n", m->key_values[i]->key, m->key_values[i]->value);
    }
}

void free_map(F_MAP *m)
{
    for (size_t i = 0; i < m->size; i++)
    {
        free(m->key_values[i]);
    }
    free(m->key_values);
    free(m);
}
int main()
{
    int arr[] = {7, 3, 5, 6, 5, 1, 3, 11, 9, 12, 5, 7, 8, 6, 3};
    int arr_size = sizeof(arr) / sizeof(int);
    F_MAP *frequency = initialize();
    for (size_t i = 0; i < arr_size; i++)
    {
        append(frequency, arr[i], get_or_default(frequency, arr[i], 0) + 1);
        // int find_flag = -1;
        // printf("fre[arr[%lld]] is %d", i, get(frequency, &find_flag, arr[i]));
    }
    print_map(frequency);
    free_map(frequency);

    return 0;
}
#include "c_string_map.h"
STRING_PAIR *make_string_pair(char *key, int value)
{
    STRING_PAIR *p = malloc(sizeof(STRING_PAIR));
    size_t key_len = strlen(key);
    p->key = malloc(sizeof(char) * (key_len + 1));
    strcpy(p->key, key);
    p->key[key_len] = '\0';
    p->value = value;
    return p;
}

int string_key_compare(const void *a, const void *b)
{
    STRING_PAIR *p1 = *(STRING_PAIR **)a;
    STRING_PAIR *p2 = *(STRING_PAIR **)b;
    return strcmp(p1->key, p2->key) > 0;
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
    if (find_in_string_map(m, key))
    {
        update_string_map(m, key, value);
        return;
    }
    if (m->size == 0)
    {
        m->key_values = malloc(sizeof(STRING_PAIR));
    }
    else
    {
        m->key_values = (STRING_PAIR **)realloc(m->key_values, sizeof(STRING_PAIR *) * (m->size + 1));
    }
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
int find_in_string_map(STRING_MAP *m, char *key)
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

int get_from_string_map(STRING_MAP *m, int *find_flag, char *key)
{
    if (!find_in_string_map(m, key))
    {
        *find_flag = 0;
        return 0;
    }
    *find_flag = 1;
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (strcmp(m->key_values[mid]->key, key) == 0)
        {
            return m->key_values[mid]->value;
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

int get_or_default_string_map(STRING_MAP *m, char *key, int default_value)
{
    if (!find_in_string_map(m, key))
    {
        return default_value;
    }
    int l = 0, r = m->size - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (strcmp(m->key_values[mid]->key, key) == 0)
        {
            return m->key_values[mid]->value;
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

void print_string_map(STRING_MAP *m)
{
    printf("All key value pairs in string map are:\n");
    for (size_t i = 0; i < m->size; i++)
    {
        printf("string: %s, frequency: %d\n", m->key_values[i]->key, m->key_values[i]->value);
    }
}

void free_string_map(STRING_MAP *m)
{
    for (size_t i = 0; i < m->size; i++)
    {
        free(m->key_values[i]);
    }
    free(m->key_values);
    free(m);
}

#include "c_frequency_map.h"
#include "c_string_map.h"
void test_int_map()
{
    int arr[] = {7, 3, 5, 6, 5, 1, 3, 11, 9, 12, 5, 7, 8, 6, 3};
    int arr_size = sizeof(arr) / sizeof(int);
    F_MAP *frequency = initialize_int_map();
    for (size_t i = 0; i < arr_size; i++)
    {
        append_int_map(frequency, arr[i], get_or_default(frequency, arr[i], 0) + 1);
        // int find_flag = -1;
        // printf("fre[arr[%lld]] is %d", i, get(frequency, &find_flag, arr[i]));
    }
    print_int_map(frequency);
    free_int_map(frequency);
}
void test_string_map()
{
    char *arr[] = {"abc", "zip", "def", "abc", "word", "abc", "def", "result", "zip", "result", "abc"};
    int arr_size = sizeof(arr) / sizeof(char *);
    STRING_MAP *frequency = initialize_string_map();
    for (size_t i = 0; i < arr_size; i++)
    {
        append_string_map(frequency, arr[i], get_or_default_string_map(frequency, arr[i], 0) + 1);

        // int find_flag = -1;
        // printf("frequency of %s is %d\n", arr[i], get_from_string_map(frequency, &find_flag, arr[i]));
    }
    print_string_map(frequency);
    free_string_map(frequency);
}
int main()
{
    test_int_map();
    test_string_map();
    return 0;
}
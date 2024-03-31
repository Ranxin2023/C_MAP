#include "c_frequency_map.h"
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
    print_map(frequency);
    free_int_map(frequency);
}

int main()
{
    test_int_map();
    return 0;
}
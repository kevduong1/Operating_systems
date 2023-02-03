#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    return *(uint16_t *)a - *(uint16_t *)b;
}
// sorts an array and validates the array upto value_count
// \param data_array the array that will be sorted using quicksort
// \param value_count the number of elements in the data_array
// \return true for successful sort, false for errors and unsuccessful
bool terrible_sort(uint16_t *data_array, const size_t value_count) {

    if(data_array == NULL || value_count == 0) return false;

    uint16_t *sorting_array = malloc(value_count * sizeof(*data_array));
    for (int i = 0; i < (int)value_count; i++) {
        sorting_array[i] = data_array[i];
    }

    qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func);

    bool sorted = true;
    for (int i = 0; i < (int)value_count - 1; ++i) {
        sorted = sorting_array[i] <= sorting_array[i + 1];
        if(!sorted) return false;
    }

    if (sorted) {
        memcpy(data_array, sorting_array, value_count * sizeof(*data_array));
    }
    return sorted;
}

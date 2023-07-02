//
// Created by vmega on 18.07.2021.
//

#include "heapsort.h"

#define HEAPSORT_SENDER "Heap sort"

void heapsort(int *array, int len) {
    sort_log_array(HEAPSORT_SENDER, "Beginning", array, len);
    heapify(array, len);
    sort_log_heap(HEAPSORT_SENDER, "Heapified", array, len);
    for(int i = len - 1; i > 0; i--) {
        swap(array, 0, i);
        heapify(array, i);
        sort_log_heap(HEAPSORT_SENDER, "Heapified", array, len);
    }
    sort_log_array(HEAPSORT_SENDER, "Sorted", array, len);
}
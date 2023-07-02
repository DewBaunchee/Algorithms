//
// Created by vmega on 18.07.2021.
//

#include "bubble_sort.h"

#define BUBBLE_SENDER "Bubble Sort"

void bubble_sort(int * array, int len) {
    sort_log_array(BUBBLE_SENDER, "Beginning", array, len);
    for(int i = 1; i < len; i++) {
        int wasNotSorted = 1;
        for(int j = 0; j < len - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(array, j, j + 1);
                sort_log_array(BUBBLE_SENDER, "Swapping", array, len);
                wasNotSorted = 0;
            }
        }
        if(wasNotSorted) break;
    }
    sort_log_array(BUBBLE_SENDER, "Sorted.", array, len);
}

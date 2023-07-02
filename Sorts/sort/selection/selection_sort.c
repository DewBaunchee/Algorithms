//
// Created by vmega on 18.07.2021.
//

#include <stdio.h>
#include "selection_sort.h"

#define SELECTION_SENDER "Selection sort"

void selection_sort(int *array, int len) {
    sort_log_array(SELECTION_SENDER, "Beginning", array, len);
    for (int i = 0; i < len; i++) {

        int indexOfMin = i;
        for(int j = i; j < len ; j++) {
            if(array[indexOfMin] > array[j]) indexOfMin = j;
        }
        sort_log_array(SELECTION_SENDER, "Index of min", &indexOfMin, 1);

        if(indexOfMin != i) {
            swap(array, i, indexOfMin);
            sort_log_array(SELECTION_SENDER, "Swapping", array, len);
        }
    }
    sort_log_array(SELECTION_SENDER, "Sorted.", array, len);
}
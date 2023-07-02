//
// Created by vmega on 18.07.2021.
//

#include "simple_insert.h"

#define SIMPLE_INSERT_SENDER "Simple insert sort"

void simple_insert_sort(int *array, int len) {
    sort_log_array(SIMPLE_INSERT_SENDER, "Beginning", array, len);
    for (int i = 1; i < len; i++) {
        sort_log_array(SIMPLE_INSERT_SENDER, "New iteration", 0, 0);

        int j = i - 1;
        while(j > 0 && array[i] < array[j - 1]) j--;

        if(j < i - 1) {
            move(array, i, j);
            sort_log_array(SIMPLE_INSERT_SENDER, "Moving", array, len);
        }
    }
    sort_log_array(SIMPLE_INSERT_SENDER, "Sorted.", array, len);
}
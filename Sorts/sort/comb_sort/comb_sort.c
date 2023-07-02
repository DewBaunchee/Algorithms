//
// Created by vmega on 18.07.2021.
//

#include "comb_sort.h"

#define COMB_SENDER "Comb Sort"
#define DECREASE_FACTOR 1.247

void comb_sort(int * array, int len) {
    sort_log_array(COMB_SENDER, "Beginning", array, len);

    int gap = len - 1;
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < len - gap; j++) {
            if(array[j] > array[j + gap]) {
                swap(array, j, j + gap);
                sort_log_array(COMB_SENDER, "Swapping", array, len);
            }
        }

        if(gap == 1) break;
        gap =(int) (gap / DECREASE_FACTOR);
    }

    sort_log_array(COMB_SENDER, "Sorted.", array, len);
}

//
// Created by vmega on 18.07.2021.
//

#include "shaker_sort.h"


#define SHAKER_SENDER "Shaker sort"

void shaker_sort(int * array, int len) {
    sort_log_array(SHAKER_SENDER, "Beginning", array, len);
    if(len > 1) {
        int left = 0;
        int right = len - 1;

        while (right - left > 1) {
            sort_log_array(SHAKER_SENDER, "New iteration", 0, 0);
            for(int i = left; i < right; i++) {
                if(array[i] > array[i + 1]) {
                    swap(array, i , i + 1);
                    sort_log_array(SHAKER_SENDER, "Swapping and going right", array, len);
                }
            }
            right--;

            for(int i = right; i >= left; i--) {
                if(array[i] > array[i + 1]) {
                    sort_log_array(SHAKER_SENDER, "Swapping and going left", array, len);
                    swap(array, i , i + 1);
                }
            }
            left++;
        }
    }
    sort_log_array(SHAKER_SENDER, "Sorted.", array, len);
}
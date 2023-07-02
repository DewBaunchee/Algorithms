//
// Created by vmega on 18.07.2021.
//

#include "merge_sort.h"
#include <stdlib.h>

#define MERGE_SENDER "Merger"

int *rec_merge(int *array, int len) {

    if (len == 1) {
        int *part = calloc(1, sizeof(int));
        part[0] = array[0];
        return part;
    }

    int leftLen = len / 2;
    int rightLen = len - leftLen;
    int *left = rec_merge(array, leftLen);
    int *right = rec_merge(array + leftLen, len - leftLen);

    if(left[0] > right[0]) {
        int * temp = left;
        left = right;
        right = temp;

        int tempLen = leftLen;
        leftLen = rightLen;
        rightLen = tempLen;
    }

    sort_log_array(MERGE_SENDER, "Merging...", 0, 0);
    sort_log_array(MERGE_SENDER, "Left part", left, leftLen);
    sort_log_array(MERGE_SENDER, "Right part", right, rightLen);

    int *merged = calloc(leftLen + rightLen, sizeof(int));
    int leftIndex = 0;
    int rightIndex = 0;
    for (int i = 0; i < len; i++) {
        if((rightIndex == rightLen || left[leftIndex] < right[rightIndex])&& leftIndex != leftLen) {
            merged[i] = left[leftIndex++];
        } else {
            merged[i] = right[rightIndex++];
        }
    }

    free(left);
    free(right);
    sort_log_array(MERGE_SENDER, "Merged", merged, len);
    return merged;
}

void merge_sort(int *array, int len) {
    sort_log_array(MERGE_SENDER, "Beginning", array, len);
    int * sorted = rec_merge(array, len);
    for(int i = 0; i < len; i++) array[i] = sorted[i];
    free(sorted);
    sort_log_array(MERGE_SENDER, "Sorted.", array, len);
}
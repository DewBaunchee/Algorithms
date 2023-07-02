//
// Created by vmega on 18.07.2021.
//

#include "quick_sort.h"

#define QUICK_SENDER "Quick Sort"

int find_focus_index(int *array, int len) {
    return len / 2;
}

void rec_sort(int *array, int len) {
    if (len < 2) return;

    sort_log_array(QUICK_SENDER, "New Iteration", array, len);
    int focus = find_focus_index(array, len);
    sort_log_array(QUICK_SENDER, "New focus", &focus, 1);

    for (int i = 0; i < len; i++) {
        int was_moved = 0;
        if ( i < focus && array[i] > array[focus]) {
            move(array, i, len - 1);
            was_moved = 1;
        } else if (i != focus && array[i] == array[focus]) {
            move(array, i, focus);
            was_moved = 1;
        } else if (i > focus && array[i] < array[focus]) {
            move(array, i, 0);
            was_moved = 1;
        }

        if (was_moved) {
            if (i < focus) {
                focus--;
                i--;
            } else {
                focus++;
            }
        }
    }
    sort_log_array(QUICK_SENDER, "Redistributed", array, len);

    int i = focus - 1;
    while (array[i] == array[focus])i--;
    int leftLen = i + 1;

    i = focus + 1;
    while (array[i] == array[focus])i++;
    int rightStart = i;

    rec_sort(array, leftLen);
    rec_sort(array + rightStart, len - rightStart);
}

void quick_sort(int *array, int len) {
    sort_log_array(QUICK_SENDER, "Beginning", array, len);
    rec_sort(array, len);
    sort_log_array(QUICK_SENDER, "Sorted.", array, len);
}
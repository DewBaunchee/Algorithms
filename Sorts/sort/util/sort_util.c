//
// Created by vmega on 18.07.2021.
//

#include "sort_util.h"
#include <stdio.h>

int is_logging = 0;

void should_keep_log(int value) {
    is_logging = value;
}

void sort_log_array(const char *sender, const char *action, int *current_state, int len) {
    if (is_logging) {
        if (len == 0)
            return;

        printf("[%s] - %s: { %d", sender, action, current_state[0]);
        for (int i = 1; i < len; i++) {
            printf(", %d", current_state[i]);
        }
        printf(" }\n");
    }
}

void sort_log_heap(const char *sender, const char *action, int *current_state, int len) {
    if (is_logging) {
        if (len == 0)
            return;

        printf("[%s] - %s:\n", sender, action);
        int i = 0;
        int level = 0;
        while (i < len) {
            int count_on_level = my_pow(2, level);
            printf("[Level %d]: ", level);
            for (int j = 0; j < count_on_level && i < len; j++) {
                printf("%d ", current_state[i]);
                i++;
            }
            level++;
            printf("\n");
        }
    }
}

void sort_log_int(const char *sender, const char *action, int current_state) {
    if (is_logging) {
        printf("[%s] - %s: %d\n", sender, action, current_state);
    }
}

int my_pow(int base, int power) {
    if (power == 0) return 1;
    return base * my_pow(base, power - 1);
}

void heapify(int *array, int len) {
    if (len < 2) return;

    for (int index = len - 1; index > -1; index--)
        while (1) {
            int largest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < len && array[leftChild] > array[largest]) {
                largest = leftChild;
            }

            if (rightChild < len && array[rightChild] > array[largest]) {
                largest = rightChild;
            }

            if (largest == index) break;

            swap(array, largest, index);
            index = largest;
        }
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void move(int *array, int from, int to) {
    if (from == to) return;

    int negativeMultiplier = to > from ? 1 : -1;
    int temp = array[from];
    for (int i = from; negativeMultiplier == 1 ? i < to : i >= to; i = i + negativeMultiplier)
        array[i] = array[i + negativeMultiplier];
    array[to] = temp;
}
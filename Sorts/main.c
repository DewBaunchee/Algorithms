#include <stdio.h>
#include "sort/sortable.h"
#include "sort/bubble/bubble_sort.h"
#include "sort/util/sort_util.h"
#include "sort/shaker/shaker_sort.h"
#include "sort/simple_insert/simple_insert.h"
#include "sort/merge_sort/merge_sort.h"
#include "sort/selection/selection_sort.h"
#include "sort/comb_sort/comb_sort.h"
#include "sort/quick_sort/quick_sort.h"
#include "sort/heapsort/heapsort.h"

void print_array(int *array, int len) {
    if (len == 0) {
        printf("{}\n");
        return;
    }

    printf("{ %d", array[0]);
    for (int i = 1; i < len; i++) printf(", %d", array[i]);
    printf(" }\n");
}

void check_array(const int *array, int len) {
    if (len < 2) {
        printf("Correct.\n");
        return;
    }

    for (int i = 1; i < len; i++) {
        if (array[i - 1] > array[i]) {
            printf("Incorrect.\n");
            return;
        }
    }
    printf("Correct.\n");
}

int main() {
    int sortable[SORTABLE_LEN] = SORTABLE;
    int len = 20;

    should_keep_log(1);
    heapsort(sortable, len);
    check_array(sortable, len);
    return 0;
}

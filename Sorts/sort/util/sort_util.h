//
// Created by vmega on 18.07.2021.
//

#ifndef SORTS_SORT_UTIL_H
#define SORTS_SORT_UTIL_H

void swap(int * array, int i, int j);
void move(int * array, int from, int to);
void sort_log_array(const char * sender, const char * action, int * current_state, int len);
void sort_log_int(const char *sender, const char *action, int current_state);
void sort_log_heap(const char *sender, const char *action, int *current_state, int len);
int my_pow(int base, int power);
void heapify(int *array, int len);
void should_keep_log(int is_logging);

#endif //SORTS_SORT_UTIL_H

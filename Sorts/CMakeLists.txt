cmake_minimum_required(VERSION 3.17)
project(Sorts C)

set(CMAKE_C_STANDARD 99)

add_executable(Sorts main.c sort/sortable.h sort/util/sort_util.c sort/util/sort_util.h sort/bubble/bubble_sort.c sort/bubble/bubble_sort.h sort/shaker/shaker_sort.c sort/shaker/shaker_sort.h sort/simple_insert/simple_insert.c sort/simple_insert/simple_insert.h sort/merge_sort/merge_sort.c sort/merge_sort/merge_sort.h sort/selection/selection_sort.c sort/selection/selection_sort.h sort/comb_sort/comb_sort.c sort/comb_sort/comb_sort.h sort/quick_sort/quick_sort.c sort/quick_sort/quick_sort.h sort/heapsort/heapsort.c sort/heapsort/heapsort.h)
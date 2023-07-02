#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.h"

int main() {
    printf("Hello, World!\n");
    int * array = calloc(2, sizeof (int));
    printf("%d %d\n", array[0], array[1]);
    return 0;
}

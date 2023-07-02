//
// Created by vmega on 19.07.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void g_free_nodes(Graph graph);

Graph_Node create_graph_node(Graph_Node links, int len) {
    Graph_Node graph_node = calloc(1, sizeof(struct SGraph));
    graph_node->index = -1;
    graph_node->links = calloc(len, sizeof(int));
    graph_node->link_count = len;
    for (int i = 0; i < len; i++) {
        graph_node->links[i] = links[i];
    }
    return graph_node;
}

void free_graph_node(Graph_Node graph_node) {
    free(graph_node->links);
    free(graph_node);
}

void print_graph_node(Graph_Node graph_node) {
    if (graph_node->link_count == 0) {
        printf("{}");
        return;
    }
    printf("{ %d", graph_node->links[0].index);
    for (int i = 1; i < graph_node->link_count; i++) {
        printf(", %d", graph_node->links[i].index);
    }
    printf(" }");
}

Graph create_graph(bool is_oriented, bool is_weighted) {
    Graph graph = calloc(1, sizeof(struct SGraph));
    graph->is_oriented = is_oriented;
    graph->is_weighted = is_weighted;
    return graph;
}

void g_set_matrix(Graph graph, int **adj_matrix, int size) {
    g_free_nodes(graph);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            
        }
    }
}

void g_add_node(Graph graph, int *links) {

}

void g_set_node(Graph graph, int index, int *links) {

}

Graph_Node g_remove_node(Graph graph, int index) {
    return 0;
}

void g_link_nodes(Graph graph, int from, int to, int weight) {

}

void g_unlink_nodes(Graph graph, int from, int to) {

}

void g_free_nodes(Graph graph) {
    for (int i = 0; i < graph->size; i++) {
        free_graph_node(graph->nodes[i]);
    }
}

void g_free(Graph graph) {
    g_free_nodes(graph);
    free(graph->nodes);
    free(graph);
}

void g_print(Graph graph) {
    if (graph->size == 0) {
        printf("Graph is empty");
        return;
    }

    printf("Graph: \n====================");
    print_graph_node(graph->nodes[0]);
    for (int i = 1; i < graph->size; i++) {
        printf(",\n");
        print_graph_node(graph->nodes[i]);
    }
    printf("===========================");
};
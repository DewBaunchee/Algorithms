//
// Created by vmega on 19.07.2021.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct SGraph_Node {
    int index;
    struct SGraph_Node * links;
    int link_count;
} * Graph_Node;

Graph_Node create_graph_node(Graph_Node links, int len);
void free_graph_node(Graph_Node graph_node);
void print_graph_node(Graph_Node graph_node);

typedef struct SGraph {
    Graph_Node * nodes;
    int size;
    bool is_oriented;
    bool is_weighted;
} * Graph;

Graph create_graph(bool is_oriented, bool is_weighted);
void g_set_matrix(Graph graph, int ** adj_matrix, int size);
void g_add_node(Graph graph, int * links);
void g_set_node(Graph graph, int index, int * links);
Graph_Node g_remove_node(Graph graph, int index);
void g_link_nodes(Graph graph, int from, int to, int weight);
void g_unlink_nodes(Graph graph, int from, int to);
void g_free(Graph graph);
void g_print(Graph graph);

#endif //GRAPH_H

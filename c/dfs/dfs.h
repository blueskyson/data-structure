#include <stdlib.h>     // malloc
#include <stdbool.h>    // bool
#include <stdio.h>      // printf

typedef struct node {
    int vertex;
    struct node *next;
} node_t;

typedef struct graph {
    int verticesNum;
    node_t **adjacencyList;
} graph_t;

graph_t *createGraph(int verticesNum) {
    graph_t *g = malloc(sizeof(graph_t));
    if (!g)
        return NULL;

    g->verticesNum = verticesNum;
    g->adjacencyList = malloc(verticesNum * sizeof(node_t*));
    if (!g->adjacencyList) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < verticesNum; i++) {
        g->adjacencyList[i] = NULL;
    }
    return g;
}

void addEdge(graph_t *g, int src, int dest) {
    node_t *node1 = malloc(sizeof(node_t));
    if (!node1) {
        return;
    }
    
    node_t *node2 = malloc(sizeof(node_t));
    if (!node2) {
        free(node1);
        return;
    }

    node1->vertex = src;
    node1->next = g->adjacencyList[dest];
    g->adjacencyList[dest] = node1;

    node2->vertex = dest;
    node2->next = g->adjacencyList[src];
    g->adjacencyList[src] = node2;
}

void dfs(graph_t *g, bool *visited, int current_vertex) {
    visited[current_vertex] = true;
    printf("Visited: %d\n", current_vertex);

    node_t *ptr = g->adjacencyList[current_vertex];
    while (ptr) {
        if (!visited[ptr->vertex]) {
            dfs(g, visited, ptr->vertex);
        }
        ptr = ptr->next;
    }
}
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// node for adjacency list
typedef struct node {
    int vertex;
    struct node *next;
} node_t;

typedef struct graph {
    int numVertices;
    node_t **adjLists;
} graph_t;

#define QSIZE 100

typedef struct queue {
    int elements[QSIZE];
    int front, rear;
} queue_t;

bool isEmpty(queue_t *q) {
    return (q->rear == -1);
}

void enqueue(queue_t *q, int element) {
    if (q->rear == QSIZE - 1) {
        printf("queue overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->elements[q->rear] = element;
}

int dequeue(queue_t *q) {
    if (isEmpty(q)) {
        return -1;
    }

    int ret = q->elements[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return ret;
}


graph_t *createGraph(int vertices) {
    graph_t *g = malloc(sizeof(graph_t));
    g->numVertices = vertices;
    g->adjLists = malloc(vertices * sizeof(node_t*));

    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }

    return g;
}

void addEdge(graph_t *g, int src, int dest) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->vertex = dest;
    new_node->next = g->adjLists[src];
    g->adjLists[src] = new_node;

    new_node = malloc(sizeof(node_t));
    new_node->vertex = src;
    new_node->next = g->adjLists[dest];
    g->adjLists[dest] = new_node;
}

void bfs(graph_t *g, int start_vertex) {
    bool *visited = malloc(g->numVertices * sizeof(bool));
    for (int i = 0; i < g->numVertices; i++)
        visited[i] = false;

    queue_t *q = malloc(sizeof(queue_t));
    q->front = -1;
    q->rear = -1;
    visited[start_vertex] = true;
    enqueue(q, start_vertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visted: %d\n", currentVertex);

        node_t *ptr = g->adjLists[currentVertex];
        while (ptr) {
            if (!visited[ptr->vertex]) {
                visited[ptr->vertex] = true;
                enqueue(q, ptr->vertex);
            }
            ptr = ptr->next;
        }
    }
}
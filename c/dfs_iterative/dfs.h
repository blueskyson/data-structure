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

#define STACKSIZE 100
typedef struct stack {
    int elements[STACKSIZE];
    int top;
} stack_t;

stack_t *createStack() {
    stack_t *s = malloc(sizeof(stack_t));
    if (!s)
        return NULL;
    s->top = -1;
    return s;
}

bool isEmpty(stack_t *s) {
    return (s->top == -1);
}

bool push(stack_t *s, int element) {
    if (s->top + 1 == STACKSIZE) {
        puts("Stack Overflow");
        return false;
    }
    s->elements[++(s->top)] = element;
    return true;
}

int peek(stack_t *s) {
    return s->elements[s->top];
}

int pop(stack_t *s) {
    if (s->top == -1) {
        puts("Stack Underflow");
        return -1;
    }
    return s->elements[(s->top)--];
}

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

void dfs(graph_t *g, int start_vertex) {
    stack_t *s = createStack();
    bool *visited = malloc(g->verticesNum * sizeof(bool));
    for (int i = 0; i < g->verticesNum; i++)
        visited[i] = false;
    
    push(s, start_vertex);
    while (!isEmpty(s)) {
        int current_vertex = pop(s);
        if (visited[current_vertex])
            continue;
        
        printf("Visited: %d\n", current_vertex);
        visited[current_vertex] = true;

        for (node_t *ptr = g->adjacencyList[current_vertex]; 
             ptr; ptr = ptr->next) {
            if (!visited[ptr->vertex]) {
                push(s, ptr->vertex);
            }
        }
    }
}
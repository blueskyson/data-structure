#include "bfs.h"

int main() {
    graph_t *g = createGraph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    bfs(g, 0);
    return 0;
}
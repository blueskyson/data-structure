#include "dfs.h"

int main() {
    graph_t *g = createGraph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    bool visited[6];
    for (int i = 0; i < 6; i++) {
        visited[i] = false;
    }
    dfs(g, visited, 0);
    return 0;
}
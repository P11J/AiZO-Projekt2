#include "FordFulkersonAlgorithm.h"
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// BFS do znajdowania ścieżki powiększającej
bool FordFulkersonAlgorithm::bfs(int** rGraph, int s, int t, int* parent, int vertices) {
    bool* visited = new bool[vertices]();
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    delete[] visited;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    delete[] visited;
    return false;
}

// Implementacja algorytmu Forda-Fulkersona
void FordFulkersonAlgorithm::execute(Graph& graph) {
    int vertices = graph.getVertices();
    int** rGraph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        rGraph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            rGraph[i][j] = graph.getEdgeWeight(i, j);
        }
    }

    int* parent = new int[vertices];
    int maxFlow = 0;

    while (bfs(rGraph, 0, vertices - 1, parent, vertices)) {
        int pathFlow = INT_MAX;
        for (int v = vertices - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = vertices - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    cout << "Maximum Flow: " << maxFlow << endl;

    for (int i = 0; i < vertices; i++) {
        delete[] rGraph[i];
    }
    delete[] rGraph;
    delete[] parent;
}
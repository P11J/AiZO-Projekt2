#include "../AlgorithmsHeadings/BellmanFordAlgorithm.h"
#include <iostream>
#include <climits>

using namespace std;

// Implementacja algorytmu Bellmana-Forda
void BellmanFordAlgorithm::execute(Graph& graph) {
    int vertices = graph.getVertices(); // Pobranie liczby wierzchołków
    int* dist = new int[vertices]; // Tablica odległości

    // Inicjalizacja odległości
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX; // Ustawienie wszystkich odległości na nieskończoność
    }
    dist[0] = 0; // Odległość wierzchołka początkowego do samego siebie to 0

    // Relaksacja wszystkich krawędzi |V| - 1 razy
    for (int i = 1; i < vertices; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int v = 0; v < vertices; v++) {
                int weight = graph.getEdgeWeight(u, v);
                if (weight && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (int u = 0; u < vertices; u++) {
        for (int v = 0; v < vertices; v++) {
            int weight = graph.getEdgeWeight(u, v);
            if (weight && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graf zawiera cykl o ujemnej wadze" << endl;
                delete[] dist;
                return;
            }
        }
    }

    // Wyświetlenie najkrótszych odległości
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex: " << i << " Distance: " << dist[i] << endl;
    }

    delete[] dist;
}
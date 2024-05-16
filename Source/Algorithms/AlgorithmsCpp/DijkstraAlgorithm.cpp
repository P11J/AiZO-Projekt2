#include "../AlgorithmsHeadings/DijkstraAlgorithm.h"

#include <iostream>
#include <climits>

using namespace std;

// Implementacja algorytmu Dijkstry
void DijkstraAlgorithm::execute(Graph& graph) {
    int vertices = graph.getVertices(); // Pobranie liczby wierzchołków
    int* dist = new int[vertices]; // Tablica odległości
    bool* sptSet = new bool[vertices]; // Tablica odwiedzin wierzchołków

    // Inicjalizacja tablic
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX; // Ustawienie wszystkich odległości na nieskończoność
        sptSet[i] = false; // Oznaczenie wszystkich wierzchołków jako nieodwiedzonych
    }

    dist[0] = 0; // Odległość wierzchołka początkowego do samego siebie to 0

    // Znalezienie najkrótszej ścieżki dla wszystkich wierzchołków
    for (int count = 0; count < vertices - 1; count++) {
        // Wybór wierzchołka o minimalnej odległości, który nie został jeszcze odwiedzony
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        int u = minIndex; // Aktualny wierzchołek o minimalnej odległości
        sptSet[u] = true; // Oznaczenie wierzchołka jako odwiedzonego

        // Aktualizacja wartości odległości sąsiednich wierzchołków
        for (int v = 0; v < vertices; v++) {
            int weight = graph.getEdgeWeight(u, v);
            if (!sptSet[v] && weight && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Wyświetlenie najkrótszych odległości
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex: " << i << " Distance: " << dist[i] << endl;
    }

    delete[] dist;
    delete[] sptSet;
}
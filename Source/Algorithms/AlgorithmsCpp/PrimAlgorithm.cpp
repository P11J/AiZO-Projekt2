
#include <iostream>
#include <climits>
#include "../../Graphs/GraphHeadings/Graph.h"
#include "../AlgorithmsHeadings/PrimAlgorithm.h"



void PrimAlgorithm::execute(Graph& graph) {
    int vertices = graph.getVertices(); // Pobranie liczby wierzchołków z grafu
    int* key = new int[vertices]; // Tablica do przechowywania kluczy
    bool* inMST = new bool[vertices]; // Tablica do oznaczania wierzchołków w MST
    int* parent = new int[vertices]; // Tablica do przechowywania MST

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX; // Inicjalizacja kluczy jako nieskończoność
        inMST[i] = false; // Inicjalizacja wierzchołków jako nieodwiedzonych
    }

    key[0] = 0; // Start od wierzchołka 0
    parent[0] = -1; // Wierzchołek 0 jest korzeniem MST

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INT_MAX, minIndex;

        // Wybór wierzchołka z minimalnym kluczem
        for (int v = 0; v < vertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        int u = minIndex; // Wierzchołek z minimalnym kluczem
        inMST[u] = true; // Dodanie wierzchołka do MST

        // Aktualizacja kluczy sąsiadów wierzchołka
        for (int v = 0; v < vertices; v++) {
            int weight = graph.getEdgeWeight(u, v);
            if (weight && !inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Wyświetlenie MST
    for (int i = 1; i < vertices; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph.getEdgeWeight(i, parent[i]) << endl;
    }

    delete[] key;
    delete[] inMST;
    delete[] parent;
}

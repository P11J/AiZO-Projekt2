
#include <iostream>
#include <algorithm>
#include "../AlgorithmsHeadings/KruskalAlgorithm.h"

using namespace std;

// Funkcja do znajdowania reprezentanta zbioru (z kompresją ścieżki)
int KruskalAlgorithm::find(int* parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Funkcja do łączenia dwóch zbiorów (z unią rangową)
void KruskalAlgorithm::unionSets(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Implementacja algorytmu Kruskala
void KruskalAlgorithm::execute(Graph& graph) {
    int vertices = graph.getVertices(); // Pobranie liczby wierzchołków
    int maxEdges = vertices * (vertices - 1) / 2; // Maksymalna liczba krawędzi w grafie
    Edge* edges = new Edge[maxEdges]; // Tablica do przechowywania krawędzi
    int edgeCount = 0; // Licznik krawędzi

    // Pobranie wszystkich krawędzi z grafu
    for (int u = 0; u < vertices; u++) {
        for (int v = u + 1; v < vertices; v++) {
            int weight = graph.getEdgeWeight(u, v);
            if (weight > 0) {
                edges[edgeCount++] = {u, v, weight};
            }
        }
    }

    // Sortowanie krawędzi według wagi
    sort(edges, edges + edgeCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int* parent = new int[vertices]; // Tablica rodziców dla zbiorów
    int* rank = new int[vertices](); // Tablica rang dla zbiorów

    // Inicjalizacja zbiorów pojedynczych elementów
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    Edge* mst = new Edge[vertices - 1]; // Tablica do przechowywania MST
    int mstCount = 0; // Licznik krawędzi w MST

    // Przechodzenie przez posortowane krawędzie i budowanie MST
    for (int i = 0; i < edgeCount && mstCount < vertices - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // Jeśli krawędź nie tworzy cyklu, dodaj ją do MST
        if (rootU != rootV) {
            mst[mstCount++] = edges[i];
            unionSets(parent, rank, rootU, rootV);
        }
    }

    // Wyświetlenie MST
    for (int i = 0; i < mstCount; i++) {
        cout << "Edge: " << mst[i].u << " - " << mst[i].v << " Weight: " << mst[i].weight << endl;
    }

    delete[] edges;
    delete[] parent;
    delete[] rank;
    delete[] mst;
}

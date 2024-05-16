#include "../GraphHeadings/Graph.h"

// Konstruktor klasy Graph
Graph::Graph(int v, bool d) : vertices(v), directed(d), edges(0) {}

// Destruktor klasy Graph
Graph::~Graph() = default;

// Metoda do wczytywania grafu z pliku
void Graph::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return;
    }

    file >> edges >> vertices;

    int u, v, weight;
    while (file >> u >> v >> weight) {
        addEdge(u, v, weight);
    }
}

// Metoda do generowania losowego grafu
void Graph::generateRandomGraph(int numVertices, int density) {
    vertices = numVertices;
    edges = (density * numVertices * (numVertices - 1)) / 100;

    // Użycie zwykłego generatora liczb losowych
    for (int i = 0; i < edges; ++i) {
        int u = rand() % vertices; // Losowy wierzchołek początkowy
        int v = rand() % vertices; // Losowy wierzchołek końcowy
        int weight = rand() % 100 + 1; // Losowa waga krawędzi z przedziału 1-100
        addEdge(u, v, weight);
    }
}

// Metoda zwracająca liczbę wierzchołków w grafie
int Graph::getVertices() const {
    return vertices;
}

// Metoda do pobierania wagi krawędzi
int Graph::getEdgeWeight(int u, int v) const {
    return 0;
}
#include "../GraphHeadings/MatrixGraph.h"

// Konstruktor klasy MatrixGraph
MatrixGraph::MatrixGraph(int v, bool d) : Graph(v, d) {
    initializeMatrix();
}

// Destruktor klasy MatrixGraph
MatrixGraph::~MatrixGraph() {
    clearMatrix();
}

// Inicjalizacja macierzy
void MatrixGraph::initializeMatrix() {
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices]();
    }
}

// Czyszczenie macierzy
void MatrixGraph::clearMatrix() {
    for (int i = 0; i < vertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

// Dodawanie krawędzi w macierzy
void MatrixGraph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    if (!directed) {
        adjMatrix[v][u] = weight;
    }
}

// Wyświetlanie macierzy
void MatrixGraph::display() {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

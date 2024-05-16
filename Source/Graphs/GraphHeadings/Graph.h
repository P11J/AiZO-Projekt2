#ifndef PROJEKT2_GRAPH_H
#define PROJEKT2_GRAPH_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> // dodane do używania funkcji rand()

using namespace std;

class Graph {
protected:
    int vertices;   // Liczba wierzchołków w grafie
    int edges;      // Liczba krawędzi w grafie
    bool directed;  // Flaga wskazująca, czy graf jest skierowany

public:
    Graph(int v, bool d);
    virtual ~Graph();

    // Metody wspólne dla obu reprezentacji grafu
    virtual void addEdge(int u, int v, int weight) = 0;
    virtual void display() = 0;
    int getVertices() const; // Dodana metoda
    int getEdgeWeight(int u, int v) const; // Metoda do pobierania wagi krawędzi
    void loadFromFile(const string& filename);
    void generateRandomGraph(int numVertices, int density); // Zmieniono nazwę parametru
};


#endif //PROJEKT2_GRAPH_H

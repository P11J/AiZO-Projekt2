
#ifndef PROJEKT2_MATRIXGRAPH_H
#define PROJEKT2_MATRIXGRAPH_H


#include "Graph.h"

class MatrixGraph : public Graph {
private:
    int** adjMatrix{};

    void initializeMatrix();
    void clearMatrix();

public:
    MatrixGraph(int v, bool d);
    ~MatrixGraph();

    // Metody specyficzne dla reprezentacji macierzowej
    void addEdge(int u, int v, int weight) override;
    void display() override;
};


#endif //PROJEKT2_MATRIXGRAPH_H

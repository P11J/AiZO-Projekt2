#ifndef PROJEKT2_DIJKSTRAALGORITHM_H
#define PROJEKT2_DIJKSTRAALGORITHM_H


#include "Algorithm.h"

class DijkstraAlgorithm : public Algorithm {
public:
    void execute(Graph& graph) override; // Implementacja algorytmu Dijkstry
};

#endif //PROJEKT2_DIJKSTRAALGORITHM_H

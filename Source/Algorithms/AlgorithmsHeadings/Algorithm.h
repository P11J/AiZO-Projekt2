#ifndef PROJEKT2_ALGORITHM_H
#define PROJEKT2_ALGORITHM_H


#include "../../Graphs/GraphHeadings/Graph.h"

class Algorithm {
public:
    virtual void execute(Graph& graph) = 0; // Metoda wirtualna do wykonania algorytmu na grafie
};

#endif //PROJEKT2_ALGORITHM_H

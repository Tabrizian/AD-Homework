//
// Created by iman on 5/6/16.
//

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H

#endif //Q2_GRAPH_H

class Graph {
private:
    int size;
    int **weight;
public:
    Graph(int **arr, int size);

    int get_weight(int i, int j);

    bool exist_edge(int i, int j);

    bool is_connected(bool *mask, int i);

    int *get_row(int i);
};

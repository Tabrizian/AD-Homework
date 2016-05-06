//
// Created by iman on 5/6/16.
//

#include "graph.h"

Graph::Graph(int **arr, int size) {
    weight = new int *[size];
    for (int k = 0; k < size; ++k) {
        weight[k] = new int[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            weight[i][j] = arr[i][j];
        }
    }

    this->size = size;
}

bool Graph::exist_edge(int i, int j) {
    if (weight[i][j] != -1)
        return true;
    else
        return false;
}

bool Graph::is_connected(bool *mask, int i) {
    for (int j = 0; j < size; ++j) {
        if (mask[j]) {
            if (j != i) {
                if (weight[i][j] != -1)
                    return true;
            }
        }
    }

    return false;
}

int  Graph::get_weight(int i, int j) {
    return weight[i][j];
}

int *Graph::get_row(int i) {
    int *what = new int[size];
    for (int j = 0; j < size; ++j) {
        what[j] = weight[i][j];
    }
    return what;
}


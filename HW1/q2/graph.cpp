//
// Created by Iman Tabrizian.
//

#include "graph.h"

graph::graph(int vertices_number) {
    adj_martix = new int *[vertices_number];
    for (int i = 0; i < vertices_number; ++i) {
        adj_martix[i] = new int[vertices_number];
    }
}

graph::~graph(){
    for (int i = 0; i < vertices_number; ++i) {
        delete adj_martix[i];
    }
    delete adj_martix;
}
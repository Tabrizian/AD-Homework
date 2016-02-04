//
// Created by Iman Tabrizian.
//

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H

#include <fstream>

#inc

class graph {
    int **adj_martix; // Adjacency Matrix
    int vertices_number;
public:
    graph(int vertices_number);

    void read_file(char *file); // Reads adjacency matrix from file.

    int *adj_vertices(int vertex); // Returns adjacent vertices of a given vertex.

    int *dfs();

    int *bfs();

    ~graph();
};

#endif //Q2_GRAPH_H

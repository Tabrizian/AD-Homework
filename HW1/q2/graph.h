//
// Created by Iman Tabrizian.
//

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H

class graph {
    int **adj_martix; // Adjacency Matrix
    int vertices_number;
public:
    graph(int vertices_number);

    graph(char *file); // Reads adjacency matrix from file.

    int *adj_vertices(int vertex); // Returns adjacent vertices of a given vertex.

    void dfs();

    void dfs(int vertex);

    void bfs();

    int get_vertices_number();

    ~graph();
};

#endif //Q2_GRAPH_H

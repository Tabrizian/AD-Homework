//
// Created by Iman Tabrizian.
//

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H

class graph {
    int **adj_martix; // Adjacency Matrix
    int vertices_number;
public:
    graph(char *file); // Reads adjacency matrix from file.

    int *adj_vertices(int vertex); // Returns adjacent vertices of a given vertex.

    bool dfs(); //DFS with default vertex which is the first vertex

    bool dfs(int vertex); // Enter -1 for reset.

    void bfs();

    int get_vertices_number();

    ~graph();
};

#endif //Q2_GRAPH_H

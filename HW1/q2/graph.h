//
// Created by Iman Tabrizian.
//
#include <queue>

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H
using namespace std;

class graph {
    /*
     * Adjacency Matrix
     */
    int **adj_martix;
    int vertices_number;
public:
    /*
     * Reads adjacency matrix from file.
     */
    graph(char *file);

    /*
     * Returns adjacent vertices of a given vertex.
     */
    int *adj_vertices(int vertex);

    /*
     * DFS with default vertex which is the first vertex
     */
    bool dfs();

    /*
     * The return type is the indicator of whether sth is printed </br>
     * or not.
     * Enter -1 for reset the states.
     */
    bool dfs(int vertex);

    /*
     * BFS with default vertex which is the first vertex
     */
    bool bfs();

    /*
     * The return type is the indicator of whether sth is printed </br>
     * or not.
     * Enter -1 for reset the states.
     */
    bool bfs(int vertex);

    int get_vertices_number();

    ~graph();

    void add_vertices_to_queue(queue<int> &children, int vertex, bool *visited);
};

#endif //Q2_GRAPH_H

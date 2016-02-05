//
// Created by Iman Tabrizian.
//
#include <queue>
#include <string>

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
    string dfs(bool &printed);

    /*
     * The return type is the indicator of whether sth is printed </br>
     * or not.
     * Enter -1 for reset the states.
     */
    string dfs(int vertex, bool &found);

    /*
     * BFS with default vertex which is the first vertex
     */
    int bfs(bool &printed);

    /*
     * The return type is the indicator of whether sth is printed </br>
     * or not.
     * Enter -1 for reset the states.
     */
    int bfs(int vertex, bool &printed);

    int get_vertices_number();

    ~graph();

private:
    void add_vertices_to_queue(queue<int> &children, int vertex, bool *visited);
};

#endif //Q2_GRAPH_H

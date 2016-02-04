//
// Created by Iman Tabrizian.
//

#ifndef Q2_GRAPH_H
#define Q2_GRAPH_H

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
};

#endif //Q2_GRAPH_H

//
// Created by Iman Tabrizian.
//

#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

graph::graph(char *file) {

    ifstream file_io(file);
    int size;
    file_io >> size;
    vertices_number = size;
    adj_martix = new int *[size];
    for (int i = 0; i < size; ++i) {
        adj_martix[i] = new int[size];
    }

    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            file_io >> adj_martix[i][j];
        }
    }
}

int *graph::adj_vertices(int vertex) {
    return adj_martix[vertex];
}

int graph::bfs(bool &printed) {
    return bfs(0,printed);
}

int graph::bfs(int vertex, bool& printed) {
    static bool *visited = new bool[vertices_number];
    queue<int> children;
    static int state = 0;
    printed = false;
    int num = 0;

    if (state == 0) {
        for (int i = 0; i < vertices_number; ++i) {
            visited[i] = false;
        }
        state = 1;
    }

    if (vertex == -1) {
        state = 0;
        return false;
    }

    if (!visited[vertex]) {
        cout << vertex << " ";
        visited[vertex] = true;
        add_vertices_to_queue(children, vertex, visited);
        printed = true;
        num++;
    }


    while (children.size() != 0) {
        cout << children.front() << " ";
        num++;
        add_vertices_to_queue(children, children.front(), visited);
        children.pop();
    }
    return num;
}

void graph::add_vertices_to_queue(queue<int> &children, int vertex, bool *visited) {
    for (int j = 0; j < vertices_number; ++j) {
        if (adj_vertices(vertex)[j] && !visited[j]) {
            children.push(j);
            visited[j] = true;
        }
    }
}

int graph::dfs(bool &printed) {
    return dfs(0, printed);
}

int graph::dfs(int vertex, bool &printed) {
    static bool *visited = new bool[vertices_number];
    static int state = 0;
    printed = false;
    if (vertex == -1) {
        state = 0;
        return 0;
    }
    if (state == 0) {
        for (int i = 0; i < vertices_number; ++i) {
            visited[i] = false;
        }
        state = 1;
    }

    for (int j = 0; j < vertices_number; ++j) {
        if (adj_vertices(vertex)[j] && !visited[j]) {
            visited[j] = true;
            printed = true;
            cout << j << " ";
            return dfs(j,printed) + 1;
        }
    }

    return 0;
}

int graph::get_vertices_number() {
    return vertices_number;
}

graph::~graph() {
    for (int i = 0; i < vertices_number; ++i) {
        delete adj_martix[i];
    }
    delete adj_martix;
}
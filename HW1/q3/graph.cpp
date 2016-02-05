//
// Created by Iman Tabrizian.
//

#include "graph.h"
#include <fstream>
#include <iostream>

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
            file_io >> adj_martix[j][i];
        }
    }
}

int *graph::adj_vertices(int vertex) {
    return adj_martix[vertex];
}

string graph::dfs(bool &printed) {
    return dfs(0, printed);
}

string graph::dfs(int vertex, bool &printed) {
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

    if(!visited[vertex]) {
        cout << vertex << " ";
        visited[vertex] = true;
    }

    for (int j = 0; j < vertices_number; ++j) {
        if (adj_vertices(vertex)[j] && !visited[j]) {
            printed = true;
            dfs(j, printed);
            visited[j] = false;
        } else if (adj_vertices(vertex)[j] && visited[j]) {
            cout << "Found a door!!!1" << endl;
            return "Hello";
        }

    }

    return "Hello";
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
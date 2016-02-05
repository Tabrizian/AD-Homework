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

string graph::dfs(int vertex, bool &found) {
    static bool *visited = new bool[vertices_number];
    static int state = 0;
    string sequence;
    found = false;
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
        sequence.append(" ");
        sequence.append(to_string(vertex));
        visited[vertex] = true;
    }else{
        sequence.erase(sequence.length() - 1);
        sequence.erase(sequence.length() - 1);
    }

    for (int j = 0; j < vertices_number; ++j) {
        if (adj_vertices(vertex)[j] && !visited[j]) {
            string temp = dfs(j, found);
            if(found)
                return sequence.append(temp);

            visited[j] = false;
        } else if (adj_vertices(vertex)[j] && visited[j]) {
            sequence.append(" ");
            sequence.append(to_string(j));
            cout << "Found a loop!!!" << endl;
            found = true;
            return sequence;
        }

    }

    return "Not found";
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
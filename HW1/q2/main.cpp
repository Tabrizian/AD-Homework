#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main() {
    graph graph1("test-cases/1.txt");
    for (int i = 0; i < graph1.get_vertices_number(); ++i) {
        graph1.dfs(i);
        cout<<endl;
    }
    return 0;
}
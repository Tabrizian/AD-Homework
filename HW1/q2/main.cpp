#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    graph graph1("test-cases/1.txt");
    graph graph2("test-cases/2.txt");
    graph graph3("test-cases/3.txt");
    int num1 = 0;
    for (int i = 0; i < graph1.get_vertices_number(); ++i) {
        bool printed = graph1.bfs(i);
        if(printed) cout<<endl;
    }
    graph1.dfs(-1);
    return 0;
}
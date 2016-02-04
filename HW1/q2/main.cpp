#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main() {
    graph graph1("test-cases/3.txt");
    for (int i = 0; i < graph1.get_vertices_number(); ++i) {
        bool printed = graph1.dfs(i);
        if(printed) cout<<endl;
    }
    graph1.dfs(-1);
    return 0;
}
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph graph1("test-cases/1.txt");
    bool printed;
    cout<< graph1.dfs(7,printed);
    return 0;

}
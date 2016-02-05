#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph graph1("test-cases/3.txt");
    bool printed;
    graph1.dfs(0,printed);
    return 0;

}
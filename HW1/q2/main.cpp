#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph graph1("test-cases/1.txt");
    graph graph2("test-cases/2.txt");
    graph graph3("test-cases/3.txt");

    int num1 = 0;
    cout << "Graph 1:" << endl;
    for (int i = 0; i < graph1.get_vertices_number(); ++i) {
        bool printed;
        int temp = graph1.bfs(i,printed);
        if (printed) cout << endl, num1 = max(temp,num1);
    }
    cout << "Number of elements of largest moallefe hamband: "<< num1 << endl;
    bool printed;
    graph1.bfs(-1,printed);

    int num2 = 0;
    cout << "Graph 2: "<< endl;
    for (int i = 0; i < graph2.get_vertices_number(); ++i) {
        bool printed;
        int temp = graph2.bfs(i,printed);
        if (printed) cout << endl, num2 = max(temp,num2);
    }
    cout << "Number of elements of largest moallefe hamband: "<< num2 << endl;
    graph2.bfs(-1, printed);

    int num3 = 0;
    cout << "Graph 3:" << endl;
    for (int i = 0; i < graph3.get_vertices_number(); ++i) {
        bool printed;
        int temp = graph3.bfs(i,printed);
        if (printed) cout << endl, num3 = max(temp,num3);
    }
    cout << "Number of elements of largest moallefe hamband: " << num3 << endl;
    graph3.bfs(-1, printed);

    if (num1 > num2 && num1 > num3)
        cout << "Graph 1 has maximum number of connected vertices" << endl;
    if (num2 > num1 && num2 > num3)
        cout << "Graph 2 has maximum number of connected vertices" << endl;
    if (num3 > num2 && num3 > num1)
        cout << "Graph 3 has maximum number of connected vertices" << endl;
    return 0;
}
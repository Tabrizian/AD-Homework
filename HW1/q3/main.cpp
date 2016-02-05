#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph graph1("test-cases/1.txt");
    bool found;
    cout << "Graph 1:" << endl;
    for (int i = 0; i < graph1.get_vertices_number(); i++) {
        string res = graph1.dfs(i, found);
        if (found) {
            cout << res << endl;
            graph1.dfs(-1, found);

            break;
        }
        graph1.dfs(-1, found);
    }
    if(!found)
        cout<<"Loop 404 not found!"<<endl;
    graph graph2("test-cases/2.txt");
    cout << "Graph 2:" << endl;
    for (int i = 0; i < graph2.get_vertices_number(); i++) {
        string res = graph2.dfs(i, found);

        if (found) {
            cout << res << endl;
            graph1.dfs(-1, found);
            break;
        }
        graph2.dfs(-1, found);
    }
    if(!found)
        cout<<"Loop 404 not found!"<<endl;
    graph graph3("test-cases/3.txt");
    cout << "Graph 3:" << endl;
    for (int i = 0; i < graph3.get_vertices_number(); i++) {
        string res = graph3.dfs(i, found);
        if (found) {
            cout << res << endl;
            graph1.dfs(-1, found);
            break;
        }
        graph3.dfs(-1, found);
    }
    if(!found)
        cout<<"Loop 404 not found!"<<endl;

    return 0;

}
#include <iostream>
#include "graph.h"

//
// Created by iman on 5/6/16.
//

using namespace std;

int min(int *arr, bool *mask, int size) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (mask[i] && arr[i] > 0) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return index;
    for (int j = index + 1; j < size; ++j) {
        if (mask[j] && (arr[j] < arr[index]) && arr[j] > 0)
            index = j;
    }

    return index;
}

int main() {

    int size;
    cin >> size;

    int **arr = new int *[size];
    for (int k = 0; k < size; ++k) {
        arr[k] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            char value;
            cin >> value;

            if (value == '*') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = ((int) value) - ((int) '0');
            }
        }
    }

    cout << "get_input()" << endl;

    Graph graph(arr, size);

    cout << "no_problem()" << endl;
    bool *mask = new bool[size];
    for (int l = 0; l < size; ++l) {
        mask[l] = true;
    }

    int index = 0;
    cout << index << " ";
    for (int m = 0; m < size; ++m) {
        mask[index] = false;
        index = min(graph.get_row(index), mask, size);
        if (index == size - 1) {
            cout << index << " ";
            break;
        }
        if (!graph.is_connected(mask, index)) continue;
        else {
            cout << index << " ";
        }

    }

    return 0;
}

#include <iostream>
#include "graph.h"

//
// Created by iman on 5/6/16.
//

using namespace std;

int min(int *arr, bool *mask, int size) {
    int index;
    for (int i = 0; i < size; ++i) {
        if (mask[i])
            index = i;
    }

    for (int j = index + 1; j < size; ++j) {
        if (mask[j] && mask[j] > arr[index])
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
                arr[i][j] = (int) value - (int) '0';
            }
        }
    }

    Graph graph(arr, size);

    bool *mask = new bool[size];
    for (int l = 0; l < size; ++l) {
        mask[l] = true;
    }

    int index = 0;
    for (int m = 0; m < size; ++m) {
        mask[index] = false;
        int index = min(graph.get_row(m), mask, size);
        if (index == size - 1) {
            cout << index << " ";
            break;
        }
        if (!graph.is_connected(mask, index)) continue;
        else cout << index << " ";

    }

    return 0;
}

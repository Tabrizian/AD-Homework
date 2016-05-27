//
// Created by iman on 5/27/16.
//

#include <iostream>
using namespace std;

void get_input(int **arr, int size) {
    for (int i = 0; i < size * size; ++i) {
        for (int j = 0; j < size * size; ++j) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    int size;
    cin >> size;

    int **arr = new int*[size * size];
    for (int i = 0; i < size * size; ++i) {
        arr[i] = new int[size * size];
    }


    return 0;
}

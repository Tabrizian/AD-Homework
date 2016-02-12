#include <iostream>
#include "equation.h"

using namespace std;

int main() {
    double **arr;
    arr = new double*[2];
    for (int i = 0; i < 2; ++i) {
        arr[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
        }
    }

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;

    cout << det(arr, 2);
    return 0;
}
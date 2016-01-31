//
// Created by Iman Tabrizian.
//

#include "lib.h"
#include <iostream>

using namespace std;

void arr_print(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
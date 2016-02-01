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

void arr_print(int *arr, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void arr_copy(int *arr_src, int *arr_dst, int size) {
    for (int i = 0; i < size; ++i) {
        arr_dst[i] = arr_src[i];
    }
}

int arr_copy(int *arr_src, int *arr_dst, int begin_src, int end_src, int begin_dst, int end_dst) {
    if (end_dst - begin_dst != end_src - begin_src)
        return -1;
    for (int i = 0; i + begin_src <= end_src; ++i) {
        arr_dst[i + begin_dst] = arr_src[i + begin_src];
    }
    return 0;
}
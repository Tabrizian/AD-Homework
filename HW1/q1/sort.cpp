//
// Created by Iman Tabrizian
//

#include "sort.h"
#include <iostream>

using namespace std;

void insert(int *arr, int index, int size) {
    for (int i = index - 1; i >= 0; --i) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
        else
            break;
    }
}

void insertion_sort(int *arr, int size) {
    if (size == 1)
        return;
    for (int i = 1; i < size; ++i) {
        insert(arr, i, size);
    }
}

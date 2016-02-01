//
// Created by Iman Tabrizian
//

#include "sort.h"
#include "lib.h"
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

int pivot(int *arr, int begin, int end) {
    int i = begin + 1;
    int j = end;
    if (i < j) {
        while (i < j) {
            while (arr[i] < arr[begin] && i < end) i++;
            while (arr[j] > arr[begin] && j > begin) j--;
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[begin], arr[j]);
    }
    return j;
}

void quick_sort(int *arr, int begin, int end) {
    if (begin >= end)
        return;
    int pivot_point = pivot(arr, begin, end);
    cout << pivot_point << endl;
    arr_print(arr, begin, end);
    quick_sort(arr, begin, pivot_point - 1);
    quick_sort(arr, pivot_point + 1, end);
}

void quick_sort(int *arr, int size) {
    quick_sort(arr, 0, size - 1);
}

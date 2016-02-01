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
    quick_sort(arr, begin, pivot_point - 1);
    quick_sort(arr, pivot_point + 1, end);
}

void quick_sort(int *arr, int size) {
    quick_sort(arr, 0, size - 1);
}

int *merge(int *arr1, int begin1, int end1, int *arr2, int begin2, int end2) {
    int *arr = new int[end1 - begin1 + end2 - begin2 + 2];
    int i = begin1;
    int j = begin2;
    int num = 0;
    while (num < end1 - begin1 + end2 - begin2 + 2) {
        if (i > end1) {
            arr[num] = arr2[j];
            j++;
            num++;
        }
        else if (j > end2) {
            arr[num] = arr1[i];
            i++;
            num++;
        }
        else if (arr1[i] < arr2[j]) {
            arr[num] = arr1[i];
            i++;
            num++;
        } else {
            arr[num] = arr2[j];
            j++;
            num++;
        }
    }
    return arr;
}

void merge_sort(int *arr, int begin, int end) {
    if (begin >= end)
        return;
    else {
        int mid = (begin + end) / 2;
        arr_print(arr, begin, end);
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        int *arr1 = new int[mid - begin + 1];
        arr_copy(arr, arr1, begin, mid, 0, mid - begin);
        int *arr2 = new int[end - mid];
        arr_copy(arr, arr2, mid + 1, end, 0, end - mid - 1);
        int *merged_arr = merge(arr1, 0, mid - begin, arr2, 0, end - mid - 1);
        arr_copy(merged_arr, arr, 0, end - begin, begin, end);
    }
}

void merge_sort(int *arr, int size) {
    merge_sort(arr, 0, size - 1);
}
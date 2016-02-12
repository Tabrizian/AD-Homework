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

void arr_copy(double **arr_src, double **arr_dst, int size, int skip_row, int skip_col){
    int row_dst = 0;
    int col_dst = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(i != skip_row && j != skip_col)
                arr_dst[i+row_dst][j+col_dst] = arr_src[i][j];
            if(i == skip_row)
                row_dst = -1;
            if(j == skip_col)
                col_dst = -1;
        }
        col_dst = 0;
    }
}
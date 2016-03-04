//
// Created by Iman Tabrizian
//



#ifndef Q1_LIB_H
#define Q1_LIB_H

void arr_print(int *arr, int size);

void arr_print(int *arr, int begin, int end);

void arr_print(double **arr, int size);

void arr_print(int **arr, int size);

void arr_copy(int *arr_src, int *arr_dst, int size);

int arr_copy(int *arr_src, int *arr_dst, int begin_src, int end_src, int begin_dst, int end_dst);

int arr_copy(double **arr_src, double **arr_dst, int size); //For copying two dimensional square array.

void arr_copy(double **arr_src, double **arr_dst, int size, int skip_row, int skip_col); //For copying two dimensional square array.

void arr_create(double ***arr,int size);

void arr_delete(double **arr, int size);

void swap(int &a, int &b);

void arr_init(int **arr, int size, int value);

void arr_random(int **arr, int size, int min_value, int max_value);
#endif //Q1_LIB_H

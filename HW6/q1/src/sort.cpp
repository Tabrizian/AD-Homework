//
// Created by iman on 4/22/16.
//
#include "sort.h"

int max(struct data *array, int *mask, int size) {
    int index;
    for (int i = 0; i < size; ++i) {
        if(mask[i] != 0) {
            index = i;
            break;
        }
    }

    for (int j = index + 1; j < size; ++j) {
        if (array[j].info > array[index].info && mask[j] == 1) {
            index = j;
        }
    }

    return index;
}

int sort(struct data * array, int size) {
   int mask[size];

    for (int i = 0; i < size; ++i) {
        mask[i] = 1;
    }


    int start = max(array, mask, size);
    int current = start;
    mask[start] = 0;

    for (int j = 1; j < size; ++j) {
       int index = max(array, mask, size);
        array[current].link = index;
        mask[index] = 0;
        current = index;
    }

    array[current].link = start;

    return start;
}

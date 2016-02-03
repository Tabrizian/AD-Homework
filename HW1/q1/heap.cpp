//
// Created by Iman Tabrizian on 2/1/2016.
//

#include "heap.h"
#include "lib.h"

void heap::insert(int data) {
    elements[++last] =  data;
    for (int i = last; i/2 > 0; i = i/2) {
        if(elements[i] > elements[i/2])
            swap(elements[i],elements[i/2]);
    }
}

void heap::print() {
    arr_print(elements, 1, last);
}


//
// Created by Iman Tabrizian on 2/1/2016.
//

#include "heap.h"
#include "lib.h"
#include <iostream>

using namespace std;

heap::heap() {
    last = 0;
}

void heap::insert(int data) {
    elements[++last] = data;
    for (int i = last; i / 2 > 0; i = i / 2) {
        if (elements[i] > elements[i / 2])
            swap(elements[i], elements[i / 2]);
    }
}

void heap::print() {
    arr_print(elements, 1, last);
}


int heap::remove() {
    int to_be_returned = elements[1];
    swap(elements[last], elements[1]);
    --last;
    for (int i = 1; i <= last / 2;) {
        int to_be_swapped = 2 * i;
        if (elements[2 * i] < elements[2 * i + 1] && ((2 * i + 1) <= last))
            to_be_swapped++;
        if (elements[to_be_swapped] > elements[i]) {
            swap(elements[to_be_swapped], elements[i]);
            i = to_be_swapped;
        }
        else break;
    }

    return to_be_returned;
}

void heap::sort_and_print() {
    while (last) {
        cout << remove() << " ";
    }
    cout << endl;
}

void heap::sort() {
    while (last) {
        remove();
    }
}



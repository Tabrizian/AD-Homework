//
// Created by Iman Tabrizian
//

#ifndef Q1_HEAP_H
#define Q1_HEAP_H

#define MAX_NUM 100
class heap {
    int elements[MAX_NUM];
    int last = 0;
public:
    heap();
    void insert(int data);
    int remove();
    void print();
    void sort_and_print();
};

#endif //Q1_HEAP_H

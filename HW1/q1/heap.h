//
// Created by Iman Tabrizian
//

#ifndef Q1_HEAP_H
#define Q1_HEAP_H

#define MAX_NUM 100
class heap {
public:
    int elements[MAX_NUM];
    int last = 0;
public:
    void insert(int data);
    int remove();
    void print();
};

#endif //Q1_HEAP_H

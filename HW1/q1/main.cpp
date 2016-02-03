#include "heap.h"
#include <iostream>

using namespace std;

int main() {
    heap heap1;
    heap1.insert(20);
    heap1.insert(30);
    heap1.insert(2);
    heap1.insert(50);
    heap1.insert(67);
    heap1.insert(22);
    heap1.insert(80);
    heap1.sort_and_print();
    return 0;
}
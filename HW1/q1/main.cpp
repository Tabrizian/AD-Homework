#include "sort.h"
#include "lib.h"
#include "heap.h"
#include <iostream>
using namespace std;

int main() {
    heap heap1;
    heap1.insert(20);
    heap1.insert(30);
    heap1.insert(2);
    heap1.insert(50);
    heap1.print();
    return 0;
}
#include "heap.h"
#include <iostream>
#include <fstream>
#include "sort.h"
#include "lib.h"

using namespace std;

int *read() {
    ifstream test_case(
            "test-cases/1000.txt");
    int *arr = new int[2000];
    for (int i = 0; i < 2000; ++i) {
        test_case >> arr[i];
    }
    return arr;

}


int main() {
    int *arr = read();
    int start_s=clock();
    quick_sort(arr, 2000);
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
//    heap heap1;
//    heap1.insert(20);
//    heap1.insert(30);
//    heap1.insert(2);
//    heap1.insert(50);
//    heap1.insert(67);
//    heap1.insert(22);
//    heap1.insert(80);
//    heap1.sort_and_print();
    return 0;
}
#include "heap.h"
#include <iostream>
#include <fstream>
#include "sort.h"
#include "lib.h"

using namespace std;

int *read() {
    ifstream test_case(
            "test-cases/2000.txt");
    int *arr = new int[2000];
    for (int i = 0; i < 2000; ++i) {
        test_case >> arr[i];
    }
    return arr;

}


int main() {
    int *arr = read();
    int start_s=clock();
    heap_sort(arr, 2000);
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}
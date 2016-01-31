#include <iostream>
#include "sort.h"
#include "lib.h"

using namespace std;

int main() {
    int arr[] = {5, 10, 20, 35, 2, 60};
    insertion_sort(arr, 6);
    arr_print(arr, 6);
    cout << "Hello, World!" << endl;
    return 0;
}
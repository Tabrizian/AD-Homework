#include "sort.h"
#include "lib.h"


int main() {
    int arr[] = {5, 10, 20, 35, 2, 60};
    merge_sort(arr, 6);
    arr_print(arr, 6);
    return 0;
}
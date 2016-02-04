//
// Created by Iman Tabrizian
//

#include <iostream>
#include <fstream>
#include "sort.h"
#include <chrono>
#include <cstring>


using namespace std;
using namespace std::chrono;

#define SIZE_OF_TEST_CASE "20000"

int *read(string num) {
    string file_name = string("test-cases/") + string(num) + string(".txt");
    ifstream test_case(file_name);
    test_case.close();
    int *arr = new int[atoi(num.c_str())];
    for (int i = 0; i < atoi(num.c_str()); ++i) {
        test_case >> arr[i];
    }

    return arr;
}


int main() {
    string num[] = {"1000", "2000", "3000", "4000", "5000", "6000", "7000",
                    "8000", "9000", "10000", "60000", "80000", "100000", "120000", "140000", "160000",
                    "180000","200000"};
    for (int i = 0; i < 18; i++) {
        int *arr = read(num[i]);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        insertion_sort(arr, atoi(num[i].c_str()));
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t2 - t1).count();
        cout << duration <<endl;
    }
    return 0;
}
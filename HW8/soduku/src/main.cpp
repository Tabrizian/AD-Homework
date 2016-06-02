//
// Created by iman on 5/27/16.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

void get_input(int **arr, int size) {
    for (int i = 0; i < size * size; ++i) {
        for (int j = 0; j < size * size; ++j) {
            cin >> arr[i][j];
        }
    }
}

// Is integer number suitable for position x and y ?
bool promising(int **arr, int x, int y, int number, int size) {
    for (int i = 0; i < size * size; ++i) {
        if (arr[x][i] == number)
            return false;
        if (arr[i][y] == number)
            return false;
    }

    int area_x;
    int area_y;

    for (int j = 0; j < size; ++j) {
        if (size * j <= x && x < size * (j + 1))
            area_x = j;
        if (size * j <= y && y < size * (j + 1))
            area_y = j;
    }

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            if (arr[k + area_x * size][i + area_y * size] == number)
                return false;
        }
    }

    return true;
}

void arr_print(int **arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << endl;
        if((i % ((int)sqrt(size))) == 0)
            for (int k = 0; k < size; ++k) {
                cout << "___" ;
            }
        cout << endl;
        for (int j = 0; j < size; ++j) {
            if((j % ((int)sqrt(size) )) == 0)
                cout << " | ";
            cout << setw(2) << setfill('0') <<  arr[i][j] << " ";
        }
    }

}

void arr_print(int **arr, int size, int **arr2) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr2[i][j] = arr[i][j];
        }
    }
}

void solve(int **arr, int point, int size) {
    if (point == (size*size) * (size*size) ) {
        arr_print(arr, size * size);
        cout << endl << endl;
    } else {
        if (arr[point % (size * size)][point / (size * size)] == 0) {
            for (int i = 0; i < size * size; ++i) {
                int **arr2 = new int *[size * size];
                for (int j = 0; j < size * size; ++j) {
                    arr2[j] = new int[size * size];
                }

                arr_print(arr, size * size, arr2);
                if (promising(arr2, point % (size * size), point / (size * size), i + 1, size)) {
                    arr2[point % (size * size)][point / (size * size)] = i + 1;
                    solve(arr2, point + 1, size);
                }
            }
        } else {
            solve(arr, point + 1, size);
        }
    }
}

int mont_carlo(int **arr, int N) {

    int r = rand();
    int i, j;
    vector<int> prom_child;

    i = 0;
    int numnodes = 1;
    int m = 1;
    int mprod = 1;

    while (m != 0 && i != N) {

        mprod = mprod * m;
        numnodes = numnodes + mprod * N;
        i++;
        m = 0;
        prom_child.clear();


        int k;
        if (arr[i % (N * N)][i / (N * N)] == 0) {
            for (k = 0; k < N * N; ++k) {

                arr_print(arr, N * N, arr);
                if (promising(arr, k % (N * N), k / (N * N), k + 1, N)) {
                    arr[i % (N * N)][i / (N * N)] = k + 1;
                    m++;
                    prom_child.push_back(k);
                }
            }
        }

        if (m != 0) {

            r = rand();
            k = r % prom_child.size();
            arr[i % (N * N)][i / (N * N)] = k + 1;
        }

    }
    return numnodes;
}
int main() {
    int size;
    cin >> size;

    int **arr = new int *[size * size];
    for (int i = 0; i < size * size; ++i) {
        arr[i] = new int[size * size];
    }

    get_input(arr, size);

    cout << mont_carlo(arr, size);
    return 0;
}

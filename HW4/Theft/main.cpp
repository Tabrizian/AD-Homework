#include <iostream>
#include "lib.h"

using namespace std;

void get_input(int **arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

void print_way(int **arr_direction, int n) {
    int x = n - 1;
    int y = n - 1;
    if (arr_direction[x][y] == -1) {
        cout << "BUSTED" << endl;
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << arr_direction[x][y];
        if (arr_direction[x][y] == 0) {
            x--;
        } else if (arr_direction[x][y] == 1) {
            y--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int **arr_initial_data = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr_initial_data[i] = new int[n];
    }

    get_input(arr_initial_data, n);


    int **arr_computed_data = new int *[n];
    for (int j = 0; j < n; ++j) {
        arr_computed_data[j] = new int[n];
    }

    for (int k = 0; k < n; ++k) {
        arr_computed_data[k][0] = arr_initial_data[k][0];
        arr_computed_data[0][k] = arr_initial_data[0][k];
    }


    int **arr_direction = new int *[n];
    for (int m = 0; m < n; ++m) {
        arr_direction[m] = new int[n];
    }
    for (int l = 1; l < n; ++l) {
        for (int i = 1; i < n; ++i) {
            if (arr_initial_data[i][l] == -1) {
                if (arr_computed_data[i][l - 1] == -1 && arr_computed_data[i - 1][l] == -1) {
                    arr_direction[i][l] = -1;
                    arr_computed_data[i][l] = -1;
                }
                else if (arr_computed_data[i][l - 1] == -1) {
                    arr_direction[i][l] = 1;
                    arr_computed_data[i][l] = arr_computed_data[i - 1][l];
                }
                else {
                    arr_direction[i][l] = 0;
                    arr_computed_data[i][l] = arr_computed_data[i][l - 1];
                    continue;
                }
            } else {
                if (arr_computed_data[i][l - 1] > arr_computed_data[i - 1][l]) {
                    arr_direction[i][l] = 1;
                    arr_computed_data[i][l] = arr_computed_data[i][l - 1] + arr_initial_data[i][l];
                }
                else if (arr_computed_data[i][l - 1] < arr_computed_data[i - 1][l]) {
                    arr_direction[i][l] = 1;
                    arr_computed_data[i][l] = arr_computed_data[i - 1][l] + arr_initial_data[i][l];
                } else if (arr_computed_data[i][l - 1] == arr_computed_data[i - 1][l]) {
                    if (arr_computed_data[i][l - 1] == -1) {
                        arr_direction[i][l] = -1;
                        arr_computed_data[i][l] == -1;
                    } else {
                        arr_direction[i][l] = 1;
                    }

                }
            }
        }
    }

    cout<<"Computed data:"<<endl;
    arr_print(arr_computed_data, n);
    print_way(arr_direction, n);
    return 0;
}
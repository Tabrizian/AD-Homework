#include <iostream>
#include <fstream>
#include "lib.h"

#define DOWN 1
#define RIGHT 0
using namespace std;

void get_input(int **arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

int get_input(int ***arr, char *filename){
    ifstream test(filename);
    int n;
    test>>n;
    *arr = new int*[n];

    for (int k = 0; k < n; ++k) {
        (*arr)[k]=new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            test>>(*arr)[i][j];
        }
    }
    test.close();

    return n;
}

void print_way(int **arr_direction, int n) {
    int x = n - 1;
    int y = n - 1;
    if (arr_direction[x][y] == -1) {
        cout << "BUSTED" << endl;
        return;
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        cout << arr_direction[x][y];
        if (arr_direction[x][y] == DOWN) {
            x--;
        } else if (arr_direction[x][y] == RIGHT) {
            y--;
        }
    }
}

int main() {
    char input_type;
    cin>>input_type;


    int **arr_initial_data;
    int n;
    if(input_type == 'f'){
        char filename[100];
        cin>>filename;
        n = get_input(&arr_initial_data,filename);
    } else {
        cin >> n;
        arr_initial_data = new int *[n];
        for (int i = 0; i < n; ++i) {
            arr_initial_data[i] = new int[n];
        }
        get_input(arr_initial_data,n);
    }

    int **arr_computed_data = new int *[n];
    for (int j = 0; j < n; ++j) {
        arr_computed_data[j] = new int[n];
    }

    int **arr_direction = new int *[n];
    for (int m = 0; m < n; ++m) {
        arr_direction[m] = new int[n];
    }

    bool minus1 = false;
    bool minus2 = false;

    arr_computed_data[0][0] = arr_initial_data[0][0];

    for (int k = 1; k < n; ++k) {
        if (arr_initial_data[k][0] == -1)
            minus1 = true;
        if (arr_initial_data[0][k] == -1)
            minus2 = true;
        if (!minus1) {
            arr_computed_data[k][0] = arr_computed_data[k - 1][0] + arr_initial_data[k][0];
            arr_direction[k][0] = DOWN;
        }
        else {
            arr_computed_data[k][0] = -1;
            arr_direction[k][0] = -1;
        }
        if (!minus2) {
            arr_computed_data[0][k] = arr_computed_data[0][k - 1] + arr_initial_data[0][k - 1];
            arr_direction[0][k] = RIGHT;
        }
        else {
            arr_computed_data[0][k] = -1;
            arr_direction[0][k] = -1;
        }
    }

    for (int l = 1; l < n; ++l) {
        for (int i = 1; i < n; ++i) {
            if (arr_initial_data[i][l] == -1) {
                if (arr_computed_data[i][l - 1] == -1 && arr_computed_data[i - 1][l] == -1) {
                    arr_direction[i][l] = -1;
                    arr_computed_data[i][l] = -1;
                }
                else if (arr_computed_data[i][l - 1] == -1) {
                    arr_direction[i][l] = RIGHT;
                    arr_computed_data[i][l] = arr_computed_data[i - 1][l];
                }
                else {
                    arr_direction[i][l] = DOWN;
                    arr_computed_data[i][l] = arr_computed_data[i][l - 1];
                    continue;
                }
            } else {
                if (arr_computed_data[i][l - 1] > arr_computed_data[i - 1][l]) {
                    arr_direction[i][l] = RIGHT;
                    arr_computed_data[i][l] = arr_computed_data[i][l - 1] + arr_initial_data[i][l];
                }
                else if (arr_computed_data[i][l - 1] < arr_computed_data[i - 1][l]) {
                    arr_direction[i][l] = DOWN;
                    arr_computed_data[i][l] = arr_computed_data[i - 1][l] + arr_initial_data[i][l];
                } else if (arr_computed_data[i][l - 1] == arr_computed_data[i - 1][l]) {
                    if (arr_computed_data[i][l - 1] == -1) {
                        arr_direction[i][l] = -1;
                        arr_computed_data[i][l] = -1;
                    } else {
                        arr_direction[i][l] = 1;
                        arr_computed_data[i][l] = arr_computed_data[i][l - 1] + arr_initial_data[i][l];
                    }

                }
            }
        }
    }

    cout << "Computed data:" << endl;
    arr_print(arr_direction, n);
    print_way(arr_direction, n);
    return 0;
}
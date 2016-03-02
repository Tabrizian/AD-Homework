#include <iostream>
#include <fstream>
#include <stack>
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

int get_input(int ***arr, char *filename) {
    ifstream test(filename);
    int n;
    test >> n;
    *arr = new int *[n];

    for (int k = 0; k < n; ++k) {
        (*arr)[k] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            test >> (*arr)[i][j];
        }
    }
    test.close();

    return n;
}

void print_way(int **arr_direction, int n) {
    int x = n - 1;
    int y = n - 1;
    stack<int> path;
    if (arr_direction[x][y] == -1) {
        cout << "BUSTED" << endl;
        return;
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        path.push(arr_direction[x][y]);
        if (arr_direction[x][y] == DOWN) {
            x--;
        } else if (arr_direction[x][y] == RIGHT) {
            y--;
        }
    }

    while(path.size() != 0){
        cout<<path.top();
        path.pop();
    }
}

void dynamic_programming() {
    char input_type;
    cin >> input_type;

    //get input
    int **arr_initial_data;
    int n;
    if (input_type == 'f') {
        char filename[100];
        cin >> filename;
        n = get_input(&arr_initial_data, filename);
    } else {
        cin >> n;
        arr_initial_data = new int *[n];
        for (int i = 0; i < n; ++i) {
            arr_initial_data[i] = new int[n];
        }
        get_input(arr_initial_data, n);
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
    arr_direction[0][0] = 0;

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

    // Dynamic programming
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
                        arr_direction[i][l] = 0;
                        arr_computed_data[i][l] = arr_computed_data[i][l - 1] + arr_initial_data[i][l];
                    }

                }
            }
        }
    }
    print_way(arr_direction, n);
}

int divide_and_conquer_find_way(int i, int j, int **arr_initial_data, int ***arr_direction) {
    static int state = 0;
    if(state == 0){
        *arr_direction = new int *[i + 1];
        for (int l = 0; l < i + 1; ++l) {
            (*arr_direction)[l] = new int[i + 1];
        }
        state++;
    }
    if (i == 0 && j == 0) {
        return 0;
    } else if (i == 0) {
        (*arr_direction)[i][j] = RIGHT;
        return divide_and_conquer_find_way(i, j - 1, arr_initial_data, arr_direction) + arr_initial_data[i][j];
    } else if (j == 0) {
        (*arr_direction)[i][j] = DOWN;
        return divide_and_conquer_find_way(i - 1, j, arr_initial_data, arr_direction) + arr_initial_data[i][j];
    } else {
        int right = divide_and_conquer_find_way(i, j - 1, arr_initial_data, arr_direction);
        int down = divide_and_conquer_find_way(i - 1, j, arr_initial_data, arr_direction);
        if (right > down) {
            (*arr_direction)[i][j] = RIGHT;
            return right + arr_initial_data[i][j];
        } else if (right < down) {
            (*arr_direction)[i][j] = DOWN;
            return down + arr_initial_data[i][j];
        } else {
            (*arr_direction)[i][j] = 0;
            return right + arr_initial_data[i][j];
        }
    }
}

void divide_and_conquer() {
    char input_type;
    cin >> input_type;

    int **arr_initial_data;
    int n;
    if (input_type == 'f') {
        char file_name[100];
        cin >> file_name;
        n = get_input(&arr_initial_data, file_name);
    } else {
        cin >> n;
        get_input(arr_initial_data, n);
    }

    int **arr_direction;
    cout << divide_and_conquer_find_way(n - 1, n - 1, arr_initial_data, &arr_direction)<<endl;
    print_way(arr_direction, n);
}

int memoization_find_way(int i, int j, int **arr_initial_data, int ***arr_direction) {
    static int state = 0;
    static int **arr_computed_data;
    if (state == 0) {
        arr_computed_data = new int *[i + 1];
        for (int k = 0; k < i + 1; ++k) {
            arr_computed_data[k] = new int[i + 1];
        }

        *arr_direction = new int *[i + 1];
        for (int l = 0; l < i + 1; ++l) {
            (*arr_direction)[l] = new int[i + 1];
        }

        arr_init(arr_computed_data, i + 1, -2);
        state++;
    }

    if (arr_computed_data[i][j] != -2) {
        return arr_computed_data[i][j];
    } else {
        if (i == 0 && j == 0) {
            return 0;
        } else if (i == 0) {
            (*arr_direction)[i][j] = RIGHT;
            return memoization_find_way(i, j - 1, arr_initial_data, arr_direction) + arr_initial_data[i][j];
        } else if (j == 0) {
            (*arr_direction)[i][j] = DOWN;
            return memoization_find_way(i - 1, j, arr_initial_data,arr_direction) + arr_initial_data[i][j];
        } else {
            int right = memoization_find_way(i, j - 1, arr_initial_data,arr_direction);
            int down = memoization_find_way(i - 1, j, arr_initial_data,arr_direction);
            if (right > down) {
                (*arr_direction)[i][j] = RIGHT;
                return right + arr_initial_data[i][j];
            } else if (right < down) {
                (*arr_direction)[i][j] = DOWN;
                return down + arr_initial_data[i][j];
            } else {
                (*arr_direction)[i][j] = 0;
                return right + arr_initial_data[i][j];
            }
        }
    }

}

void memoization() {
    char input_type;
    cin >> input_type;

    int **arr_initial_data;
    int n;
    if (input_type == 'f') {
        char file_name[100];
        cin >> file_name;
        n = get_input(&arr_initial_data, file_name);
    } else {
        cin >> n;
        get_input(arr_initial_data, n);
    }

    int **arr_direction;
    cout << memoization_find_way(n - 1, n - 1, arr_initial_data, &arr_direction)<<endl;
    print_way(arr_direction, n);
}

int main() {
    divide_and_conquer();
    return 0;
}
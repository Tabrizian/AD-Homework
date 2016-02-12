#include <iostream>
#include "equation.h"
#include "lib.h"

using namespace std;

int main() {
    int n;
    cin >> n; //Number of equations
    double **arr_coefficients;

    arr_coefficients = new double *[n];
    for (int i = 0; i < n; ++i) {
        arr_coefficients[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr_coefficients[i][j];
        }
    }
    double *arr_c = new double[n];
    for (int l = 0; l < n; ++l) {
        cin >> arr_c[l];
    }

    double det_coefficients = det(arr_coefficients, n);

    for (int k = 0; k < n; ++k) {
        double **arr;
        arr_create(&arr, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == k)
                    arr[i][j] = arr_c[i];
                else
                    arr[i][j] = arr_coefficients[i][j];
            }
        }
        double ans = det(arr, n) / det_coefficients;
        cout << "Solution " << k << " is " << ans <<endl;
        arr_delete(arr, n);
    }

    return 0;
}
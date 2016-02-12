//
// Created by iman on 2/12/16.
//

#include "equation.h"
#include "lib.h"

double det(double **arr, int size) {
    if (size == 1)
        return arr[0][0];
    else {
        double ans = 0;
        int sign = 1;
        for (int i = 0; i < size; ++i) {
            double **arr_temp = new double *[size - 1];

            for (int j = 0; j < size - 1; ++j) {
                arr_temp[j] = new double[size - 1];
            }
            arr_copy(arr, arr_temp, size, 0, i);
            ans += sign * det(arr_temp, size - 1) * arr[0][i];
            sign = sign * -1;
        }
        return ans;
    }

}

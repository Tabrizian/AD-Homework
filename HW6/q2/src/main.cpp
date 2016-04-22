#include <iostream>

using namespace std;

int find_max(int *arr, int size) {
    int max = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = i;

    }

    return max;
}

bool is_array_zero(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] != 0)
            return false;
    }

    return true;
}

int main() {

    int size;
    cin >> size;

    int arr[size][size];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> arr[i][j];
        }

    }

    int amount[size];
    for (int m = 0; m < size; ++m) {
        amount[m] = 0;
    }

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            amount[k] += arr[i][k];
        }
    }

    int res = 1;

    int ans[size];
    for (int n = 0; n < size; ++n) {
        ans[n] = 1;
    }

    while (!is_array_zero(amount, size)) {
        int max_index = find_max(amount, size);
        amount[max_index] = 0;

        bool one_time_true = false;
        for (int l = 0; l < size; ++l) {
            if (arr[l][max_index] == 1) {
                if (ans[l] == ans[max_index]) {
                    ans[l]++;
                    res++;
                }
                arr[l][max_index] = 0;
            }

        }

    }

    cout << res - 1 << endl;
    for (int i1 = 0; i1 < size; ++i1) {
        cout << i1 << ":" << " " << ans[i1]<<endl;

    }


    return 0;
}
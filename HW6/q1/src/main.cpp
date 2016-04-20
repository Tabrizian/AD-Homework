#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int n;
    cin >> n;

    int a[n];
    int b[n];

    for(int i = 0; i < n;i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n;i++) {
        cin >> b[i];
    }

    int res[n][n];

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < n;j++) {
            int ans = min(a[i], b[j]);
            res[i][j] = ans;
            a[i] = a[i] - ans;
            b[j] = b[j] - ans;
        }
    }
}

#include <iostream>
#include "sort.h"
#include "main.h"

using namespace std;
int main() {
    int n;
    cin >> n;

    struct data a[n];
    struct data b[n];

    for(int i = 0; i < n;i++) {
        cin >> a[i].info;
        a[i].link = i + 1;
    }

    for(int i = 0; i < n;i++) {
        cin >> b[i].info;
        b[i].link = i + 1;
    }

    int a_start = sort(a, n);
    int b_start = sort(b, n);

    int answer[n][n];

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            answer[i][j] = 0;
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if(a[a_start].info != 0 && b[b_start].info != 0 ) {
                answer[j][i] = 1;
                a_start = a[a_start].link;
            } else if(a[a_start].info == 0 && b[b_start].info != 0) {
                b_start = b[b_start].link;
            }

        }
    }
}

#include <iostream>
using namespace std;

int count_ways(int n) {
    if(n == 3)
        return 1;
    if(n == 5)
        return 1;
    if(n == 7)
        return 1;
    if(n < 3)
        return 0;

    return count_ways(n - 5) + count_ways(n - 7) + count_ways(n - 3);
}

int main() {

    int n;
    cin >> n;

    cout << count_ways(n) << endl;
    return 0;
}

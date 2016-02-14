#include <iostream>

using namespace std;

int derangment(int n) {
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return (n - 1) * (derangment(n - 1) + derangment(n - 2));
}

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {

    int n;
    cout << "Enter the n:";
    cin >> n;
    int parish = derangment(n);
    int factorial = fact(n);
    int bmm = gcd(parish, factorial);
    cout << parish / bmm << " / " << factorial / bmm << endl;
    return 0;
}
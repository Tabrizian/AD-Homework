#include <iostream>

using namespace std;

double create_random() {
    double random = ((double) rand() / RAND_MAX);
    return random;
}

int main() {
    int n;
    cin>>n;
    double *pieces = new double[n];
    for (int i = 0; i < n; ++i) {
        cin>>pieces[i];
    }
    
    return 0;
}
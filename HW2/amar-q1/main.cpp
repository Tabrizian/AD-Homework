#include <iostream>

using namespace std;

double create_random() {
    time_t time = clock();
    srand(time);
    double random = ((double)rand()) / RAND_MAX;
    return random;
}

int main() {
    int n;
    cin >> n;
    int blues = 0, reds = 0;
    double probability;
    cin>>probability;
    for (int i = 0; i < n; i++) {
        double rnd = create_random();
        if (rnd < probability)
            reds++;
        else
            blues++;
    }

    cout << ((double) reds) / n;
    return 0;
}
#include <iostream>

using namespace std;

double create_random() {
    time_t time = clock();
    srand(time);
    double random = ((double) rand()) / RAND_MAX;
    return random;
}

int main() {
    int blues = 0, reds = 0;
    double probability;
    cin >> probability;
    for (int i = 0; i < 30; i++) {
        double rnd = create_random();
        if (rnd < probability)
            reds++;
        else
            blues++;
    }

    cout << "Number of seeing reds in 30 times :" << ((double) reds) / 30 << endl;

    blues = 0;
    reds = 0;
    for (int i = 0; i < 300; i++) {
        double rnd = create_random();
        if (rnd < probability)
            reds++;
        else
            blues++;
    }

    cout << "Number of seeing reds in 300 times :" << ((double) reds) / 300 << endl;

    blues = 0;
    reds = 0;
    for (int i = 0; i < 3000; i++) {
        double rnd = create_random();
        if (rnd < probability)
            reds++;
        else
            blues++;
    }

    cout << "Number of seeing reds in 3000 times :" << ((double) reds) / 3000 << endl;

    blues = 0;
    reds = 0;
    for (int i = 0; i < 30000; i++) {
        double rnd = create_random();
        if (rnd < probability)
            reds++;
        else
            blues++;
    }

    cout << "Number of seeing reds in 30000 times :" << ((double) reds) / 30000 << endl;
    return 0;
}
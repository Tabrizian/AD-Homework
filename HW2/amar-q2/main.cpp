#include <iostream>

using namespace std;

double create_random() {
    double random = ((double) rand() / RAND_MAX);
    return random;
}

int main() {
    int n;
    cin >> n;
    double *pieces = new double[n];
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i];
    }

    double sum = 0;
    for (int m = 0; m < n; ++m) {
        sum += pieces[m] * (m + 1);
    }

    cout << "The expected value is: " << sum / n << endl;

    for (int k = 1; k < n; ++k) {
        pieces[k] += pieces[k - 1];
    }


    int *repeats = new int[n];
    for (int l = 0; l < n; ++l) {
        repeats[l] = 0;
    }

    for (int j = 0; j < 30; ++j) {
        double rand = create_random();
        for (int i = 0; i < n; ++i) {
            if (rand < pieces[i]) {
                repeats[i]++;
                break;
            }

        }
    }

    sum = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        sum += ((double)repeats[i1]) / 30 * (i1 + 1);
    }

    cout << "The expected value for n = 30 is: " << sum / n << endl;
    for (int l = 0; l < n; ++l) {
        repeats[l] = 0;
    }

    for (int j = 0; j < 300; ++j) {
        double rand = create_random();
        for (int i = 0; i < n; ++i) {
            if (rand < pieces[i]) {
                repeats[i]++;
                break;
            }

        }
    }

    sum = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        sum += ((double)repeats[i1]) / 300 * (i1 + 1);
    }

    cout << "The expected value for n = 300 is: " << sum / n << endl;
    for (int l = 0; l < n; ++l) {
        repeats[l] = 0;
    }

    for (int j = 0; j < 3000; ++j) {
        double rand = create_random();
        for (int i = 0; i < n; ++i) {
            if (rand < pieces[i]) {
                repeats[i]++;
                break;
            }

        }
    }

    sum = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        sum += ((double)repeats[i1]) / 3000 * (i1 + 1);
    }

    cout << "The expected value for n = 3000 is: " << sum / n << endl;
    for (int l = 0; l < n; ++l) {
        repeats[l] = 0;
    }

    for (int j = 0; j < 30000; ++j) {
        double rand = create_random();
        for (int i = 0; i < n; ++i) {
            if (rand < pieces[i]) {
                repeats[i]++;
                break;
            }

        }
    }

    sum = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        sum += ((double)repeats[i1]) / 30000 * (i1 + 1);
    }

    cout << "The expected value for n = 30000 is: " << sum / n << endl;
    return 0;
}
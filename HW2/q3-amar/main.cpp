#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream input("distributions/poisson.txt");
    int n;
    int num = 0;
    int sum = 0;
    double avg;
    while (input >> n) {
        sum += n;
        num++;
    }

    avg = ((double) sum / num);
    cout<<"poisson.txt: "<<endl;
    cout << "Average is: " << avg << endl;
    input.clear();
    input.seekg(0, ios_base::beg);

    int variance = 0;
    while (input >> n) {
        variance += (n - avg) * (n - avg);
    }

    variance = variance / num;
    cout <<"Variance is: "<< variance << endl;
    cout<<"Enheraf meyar: " << sqrt(variance) <<endl;
    input.close();
    input.open("distributions/normal.txt");
    while (input >> n) {
        sum += n;
        num++;
    }

    cout <<endl;
    avg = ((double) sum / num);
    cout<<"sample.txt: "<<endl;
    cout << "Average is: " << avg << endl;
    input.clear();
    input.seekg(0, ios_base::beg);

    variance = 0;
    while (input >> n) {
        variance += (n - avg) * (n - avg);
    }

    variance = variance / num;
    cout <<"Variance is: "<< variance << endl;
    cout<<"Enheraf meyar: " << sqrt(variance) <<endl;
    input.close();
    return 0;
}
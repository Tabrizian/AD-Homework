#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream input("distributions/normal.txt");
    double n;
    double num = 0;
    double sum = 0;
    double avg;
    while (input >> n) {
        sum += n;
        num++;
    }

    avg = ((double) sum / num);
    cout<<"normal.txt: "<<endl;
    cout << "Average is: " << avg << endl;
    input.clear();
    input.seekg(0, ios_base::beg);

    int variance = 0;
    while (input >> n) {
        variance += (n - avg) * (n - avg);
    }

    variance = variance / num;
    cout <<"Variance is: "<< variance << endl;
    cout<<"Standard Deviation: " << sqrt(variance) <<endl;
    input.close();

    cout << endl;
    ifstream input2("distributions/poisson.txt");
    num = 0;
    sum = 0;
    while (input2 >> n) {
        sum += n;
        num++;
    }

    avg = ((double) sum / num);
    cout<<"poisson.txt: "<< endl;
    cout << "Average is: " << avg << endl;
    input2.clear();
    input2.seekg(0, ios_base::beg);

    variance = 0;
    while (input2 >> n) {
        variance += (n - avg) * (n - avg);
    }

    variance = variance / num;
    cout <<"Variance is: "<< variance << endl;
    cout<<"Standard Deviation: " << sqrt(variance) <<endl;
    input.close();
    return 0;
}
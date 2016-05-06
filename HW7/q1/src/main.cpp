#include <iostream>

#include "cache.h"

using namespace std;

int main() {
    int k,n;

    cin>>k>>n;

    char *dataset = new char[n + 1];

    for(int i = 0;i < n;i++) {
        cin>>dataset[i];
    }

    Cache cache(k, dataset, n);

    int miss = 0;
    for(int i = 0;i < n;i++) {
        if(!cache.read(dataset[i]))
            miss++;
    }

    cout<<miss<<endl;
    return 0;
}

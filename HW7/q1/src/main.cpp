#include <iostream>

#include "cache.h"

using namespace std;

int main() {
    int k,n;

    cin>>n>>k;

    char *dataset = new char[n];

    for(int i = 0;i < n;i++) {
        cin>>dataset[i];
    }
    Cache cache(k, dataset, n);

    int miss = 0;
    for(int i = 0;i < n;i++) {
        cache.read(dataset[i]) ? miss : miss++;
    }

    cout<<miss<<endl;
    return 0;
}

#include "cache.h"

#include <iostream>

using namespace std;
Cache::Cache(int k, char *dataset, int size) {
    this->k = k;
    this->data = new char[k];

    for(int i = 0; i < k ;i++) {
        this->data[i] = 0;
    }

    this->index = 0;
    this->dataset = dataset;
    this->size = size;
}

bool Cache::read(char c) {
    cout << c << ": ";

    for(int i = 0; i < k; i++) {
        if(this->data[i] == c) {
            print();
            return true;
        }
    }

    this->data[replacement()] = c;
    print();
    index++;

    return false;
}

int Cache::replacement() {
    int max = 0;

    if(is_room() != -1)
        return is_room();

    int to_be = 0;
    for(int i = 0;i < k; i++) {
        int next_use = used_index(this->data[i]);
        if(next_use == -1) {
            return i;
        } else {
            if(next_use > max) {
                max = next_use;
                to_be = i;
            }
        }
    }

    return to_be;
}

int Cache::used_index(char c) {

    for(int i = index + 1; i < size; i++) {
        if(this->dataset[i] == c) {
            return i;
        }
    }

    return -1;
}

int Cache::is_room() {
    for(int i = 0; i < k;i++) {
        if(this->data[i] == 0)
            return i;
    }

    return -1;
}

void Cache::print() {
    for(int i = 0;i < k;i ++) {
        if(data[i] != 0) {
            cout << data[i] << " ";
        }
    }

    cout<<endl;
}


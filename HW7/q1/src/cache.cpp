#include "cache.h"

Cache::Cache(int k, char *dataset, int size) {
    this->k = k;
    this->data = new char[k];

    for(int i = 0; i < k ;i++) {
        this->data[i] = 0;
    }

    this->index = 0;
}

bool Cache::read(char c) {
    for(int i = 0; i < k; i++) {
        if(this->data[i] == c)
            return true;
    }

    this->data[replacement()] = c;
    index++;

    return false;
}

int Cache::replacement() {
    int max = 0;

    for(int i = 0;i < k; i++) {
        if(used_index(this->data[i]) > max)
            max = used_index(this->data[i]);
    }

    return max;
}

int Cache::used_index(char c) {

    for(int i = index; i < size; i++) {
        if(this->dataset[i] == c) {
            return i;
        }
    }

    return -1;
}


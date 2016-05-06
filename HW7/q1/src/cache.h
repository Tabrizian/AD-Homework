#ifndef CACHE_H
#define CACHE_H

class Cache {
    private:
        int k;
        char *data;
    public:
        void Cache(int k);
        bool read(char c);
    private:
        int replacement();
}

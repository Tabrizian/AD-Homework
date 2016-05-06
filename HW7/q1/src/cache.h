#ifndef CACHE_H
#define CACHE_H
#endif

class Cache {
private:
    int k;
    char *data;
    char *dataset;
    int size;
    int index;
public:
    Cache(int k, char *dataset, int size);

    bool read(char c);

private:
    int replacement();

    int replacement_two();

    int used_index(char c);

    void print();

    int is_room();
};

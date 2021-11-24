#include<iostream>
#include<assert.h>
#include "List.h"

using namespace std;

template <typename E>
class Array : public List<E> {
    E *arr;
    int capacity;
    int size;
    int pos;
    int chunk;

    void init() {
        arr = new E[1];
        capacity = 1;
        size = 0;
        pos = 0;
    }

    void resize() {
        assert(chunk > 0);
        capacity += chunk;
        E *tmp = new E[capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    Array(int x = 8) {
        assert(x > 0);
        chunk = x;
        init();
    }

    Array(const E *arr, int x = 8) {
        size = sizeof(arr) / sizeof(E);
        assert(x > 0 && x >= size);
        capacity = chunk = x;
        this->arr = new E[capacity];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
        pos = 0;
    }

    ~Array() {
        delete[] arr;
    }

    void clear() {
        delete[] arr;
        init();
    }

    void insert(const E &item) {
         if (size == capacity) resize();
         for (int i = size++; i > pos; i--) {
            arr[i] = arr[i-1];
         }
         arr[pos] = item;
    }

    void append(const E &item) {
        if (size == capacity) resize();
        arr[size++] = item;
    }

    E remove() {
        assert(pos < size);
        E ret = arr[pos];
        for (int i = pos; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        --size;
        return ret;
    }

    void moveToStart() {
        pos = 0;
    }

    void moveToEnd() {
        pos = size - 1;
    }

    void prev() {
        if (pos > 0) --pos;
    }

    void next() {
        if (pos < size) ++pos;
    }

    int length() {
        return size;
    }

    int currPos() {
        return pos;
    }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos <= size);
        this->pos = pos;
    }

    E getValue() {
        assert(pos < size);
        return arr[pos];
    }

    int Search(const E &item) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) return i;
        }
        return -1;
    }
};

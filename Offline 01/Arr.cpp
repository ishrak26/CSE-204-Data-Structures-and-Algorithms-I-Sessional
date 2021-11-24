#include<iostream>
#include<assert.h>
#include "List.h"

using namespace std;

template <typename E>
class Arr : public List<E> {
    E *arr;
    int capacity;
    int size;
    int pos;
    int chunk;

    void init(int x, int cap = 1) {
        chunk = x;
        capacity = cap;
        arr = new E[capacity];
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
    Arr(int x = 8) {
        assert(x > 0);
        init(x);
    }

    Arr(List<E> *L, int x = 8) {
        assert(x > 0 && x >= L->length());
        init(x, x);

        int tmp = L->currPos();
        for (L->moveToStart(); L->currPos() < L->length(); L->next()) {
            append(L->getValue());
        }
        L->moveToPos(tmp);
    }

    ~Arr() {
        delete[] arr;
    }

    void clear() {
        delete[] arr;
        init(chunk);
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

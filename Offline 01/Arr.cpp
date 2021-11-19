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

    void init() {
        arr = new E[1];
        capacity = 1;
        size = 0;
        pos = 0;
    }

    void resize() {
        capacity <<= 1;
        E *tmp = new E[capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    Array() {
        init();
    }

    Array(const E *arr) {
        capacity = sizeof(arr) / sizeof(E);
        this->arr = new E[capacity];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
        size = capacity;
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
         for (int i = size++; i >= pos; i--) {
            arr[i] = arr[i-1];
         }
         arr[pos] = item;
    }

    void append(const E &item) {
        if (size == capacity) resize();
        arr[size++] = item;
    }

    E remove() {
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
        pos = size;
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

    void printList() {
        for (int i = 0; i < pos; i++) {
            cout << arr[i] << " ";
        }
        cout << "|";
        for (int i = pos; i < size; i++) {
            cout << " " << arr[i];
        }
        cout << "\n";
    }
};

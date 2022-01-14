#include <cassert>

using namespace std;

// max-heap for int
class Heap {
    int *arr;
    int sz;
    int capacity;

    // doubles the size
    void resize() {
        capacity <<= 1;
        int *new_arr = new int[capacity+1];
        for (int i = 1; i <= sz; i++) new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }

    inline int parent(int i) { return i>>1; }
    inline int left_child(int i) { return i<<1; }
    inline int right_child(int i) { return (i<<1) | 1; }

    void max_heapify(int i) { // O(logn)
        int l = left_child(i);
        int r = right_child(i);
        int ma = l <= sz && arr[l] > arr[i] ? l : i;
        ma = r <= sz && arr[r] > arr[ma] ? r : ma;
        if (i != ma) {
            swap(arr[i], arr[ma]);
            max_heapify(ma); // tail recursion
        }
    }

    void build_max_heap() { // O(n)
        for (int i = sz>>1; i > 0; i--) max_heapify(i);
    }

public:
    // construct empty heap with given capacity
    Heap(int capacity) {
        this->capacity = capacity;
        sz = 0;
        arr = new int[capacity+1];
    }

    // construct heap from given vector
    Heap(const vector<int>& v) { // O(n)
        capacity = sz = v.size();
        arr = new int[capacity+1];
        for (int i = 0; i < sz; i++) arr[i+1] = v[i]; // O(n)
        build_max_heap(); // O(n)
    }

    ~Heap() {
        delete[] arr;
    }

    // insert val into heap
    void insert(int val) { // O(logn)
        if (sz == capacity) resize();
        arr[++sz] = val;
        // percolate up
        for (int i = sz; i > 1 && arr[parent(i)] < arr[i]; i = parent(i)) {
            swap(arr[i], arr[parent(i)]);
        }
    }

    int size() {
        return sz;
    }

    // returns max val
    int getMax() { // O(1)
        assert(sz); // heap is non-empty
        return arr[1];
    }

    // deletes root of the heap
    void deleteKey() { // O(logn)
        assert(sz); // heap is non-empty
        arr[1] = arr[sz--];
        max_heapify(1); // O(logn)
    }
};

void heapsort(vector<int>& v) { // sorts in descending order
    Heap h(v); // O(n)
    for (int i = 0, sz = v.size(); i < sz; i++) {
        v[i] = h.getMax(); // O(1)
        h.deleteKey(); // O(logn)
    }
    // Total complexity: O(nlogn)
}

#include<vector>

using namespace std;

int partition(vector<int>& v, int lo, int hi, bool randomized) {
    if (randomized) {
        int idx = rand() % (hi-lo+1) + lo;
        swap(v[idx], v[hi]);
    }
    int i = lo-1;
    for (int j = lo; j < hi; j++) {
        if (v[j] <= v[hi]) {
            swap(v[++i], v[j]);
        }
    }
    swap(v[++i], v[hi]);
    return i;
}

void quicksort(vector<int>& v, bool randomized=true, int lo = 0, int hi = -1) {
    if (hi < 0) hi = v.size()-1; // if called by user
    if (lo >= hi) return;
    int mid = partition(v, lo, hi, randomized);
    quicksort(v, randomized, lo, mid-1);
    quicksort(v, randomized, mid+1, hi);
}

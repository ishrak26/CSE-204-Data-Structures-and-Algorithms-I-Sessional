#include<vector>

using namespace std;

// partitions the arr in the range lo to hi in two parts
// left part is greater than or equal to
// right part is less than
int partition(long long *arr, int lo, int hi) {
    int idx = rand() % (hi-lo+1) + lo;
    swap(arr[idx], arr[hi]);
    int i = lo-1;
    for (int j = lo; j < hi; j++) {
        if (arr[j] >= arr[hi]) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[hi]);
    return i;
}

// sorts arr in descending order in the range lo to hi
void quicksort_descending(long long *arr, int lo, int hi) {
    if (lo >= hi) return;
    int mid = partition(arr, lo, hi);
    quicksort_descending(arr, lo, mid-1);
    quicksort_descending(arr, mid+1, hi);
}

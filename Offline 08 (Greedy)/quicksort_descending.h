#include<vector>

using namespace std;

int partition(int *arr, int lo, int hi) {
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

void quicksort_descending(int *arr, int lo, int hi) {
    if (lo >= hi) return;
    int mid = partition(arr, lo, hi);
    quicksort_descending(arr, lo, mid-1);
    quicksort_descending(arr, mid+1, hi);
}

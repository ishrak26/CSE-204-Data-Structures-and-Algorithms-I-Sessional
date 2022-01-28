#include<vector>
#include<cassert>

using namespace std;

void merge(vector<int>& v, int lo, int mid, int hi) {
    // v1 is from lo to mid
    // v2 is from mid+1 to hi
    int sz1 = mid-lo+1;
    int sz2 = hi-mid;
    vector<int> v1(sz1), v2(sz2);
    for (int i = 0; i < sz1; i++) v1[i] = v[lo + i];
    for (int i = 0; i < sz2; i++) v2[i] = v[mid+1 + i];
    int i, j, k;
    for (i = j = 0, k = lo; ; k++) {
        if (i == sz1) {
            // copy rest from v2
            for (; j < sz2; j++, k++) v[k] = v2[j];
            break;
        }
        if (j == sz2) {
            // copy rest from v1
            for (; i < sz1; i++, k++) v[k] = v1[i];
            break;
        }
        v[k] = v1[i] < v2[j] ? v1[i++] : v2[j++];
    }
    assert(i==sz1 && j==sz2 && k==hi+1);
}

void merge_sort(vector<int>& v, int lo = 0, int hi = -1) {
    if (hi < 0) hi = v.size()-1; // if called by user
    if (lo >= hi) return;
    int mid = (lo+hi)/2;
    merge_sort(v, lo, mid);
    merge_sort(v, mid+1, hi);
    merge(v, lo, mid, hi);
}

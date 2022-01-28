#include<vector>

using namespace std;

void insertion_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 2; i < n; i++) {
        int val = v[i];
        int j;
        for (j = i-1; j >= 0 && v[j] > val; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = val;
    }
}

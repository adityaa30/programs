#include <bits/stdc++.h>
#define li long long int
using namespace std;

li BinarySearch(li arr[], li l, li r, li key) {
    if (r >= l) {
        li m = l + (r - l) / 2;
        if(arr[m] == key) return m;

        if(arr[m] > key) return BinarySearch(arr, l, m - 1, key);
        return BinarySearch(arr, m + 1, r, key);
    }
    return -1;
}

li FindPivot(li arr[], li l, li r) {
    if (r < l) return -1;
    if (r == l) return l;

    li m = l + (r - l) / 2;
    if(m < r && arr[m] > arr[m + 1]) return m;
    if(m > l && arr[m - 1] > arr[m]) return m - 1;

    if(arr[l] >= arr[m]) return FindPivot(arr, l, m - 1);
    
    return FindPivot(arr, m + 1, r);
}

li PivotedBinarySearch(li arr[], li n, li key) {
    li pivot = FindPivot(arr, 0, n - 1);
    if (pivot == -1) return BinarySearch(arr, 0, n - 1, key);

    if(arr[pivot] == key) return pivot;

    if(arr[0] <= key) return BinarySearch(arr, 0, pivot - 1, key);

    return BinarySearch(arr, pivot + 1, n - 1, key);
}

int main() {
    li n, key;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> key;
    cout << PivotedBinarySearch(arr, n, key) << endl;
    return 0;
}
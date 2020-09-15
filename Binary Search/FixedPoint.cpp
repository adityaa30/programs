#include <bits/stdc++.h>
#define li long long int
using namespace std;

li FixedPoint(li arr[], li l, li r) {
    if (r >= l) {
        li m = l + (r - l) / 2;
        if(arr[m] == m) return m;
        if(arr[m] > m) return FixedPoint(arr, l, m - 1);
        return FixedPoint(arr, m + 1, r);
    }
    return -1;
}

int main() {
    li n;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << FixedPoint(arr, 0, n - 1) << endl;
    return 0;
}
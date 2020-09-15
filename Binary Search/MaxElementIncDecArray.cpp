#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Maximum(li arr[], li l, li r) {
    if (r >= l) {
        li m = l + (r - l) / 2;
        if (l + 1 == r) return max(arr[l], arr[r]); 
        if(m + 1 <= r && m - 1 >= l && arr[m] > arr[m + 1] && arr[m] > arr[m - 1]) return m;
        if(m + 1 <= r && m - 1 >= l && arr[m] > arr[m + 1] && arr[m] < arr[m - 1]) return Maximum(arr, l, m - 1);
        if(m + 1 <= r && m - 1 >= l && arr[m] < arr[m + 1] && arr[m] > arr[m - 1]) return Maximum(arr, m + 1, r);
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
    cout << Maximum(arr, 0, n - 1) << endl;
    return 0;
}
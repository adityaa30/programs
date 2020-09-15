#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Find1(li arr[], li l, li r) {
    if(r >= l) {
        li m = l + (r - l) / 2;
        if(m - 1 >= l && arr[m - 1] == 0 && arr[m] == 1) return m;
        if(arr[m] == 1) return Find1(arr, l, m - 1);
        else return Find1(arr, m + 1, r);
    }
    return -1;
}

int main() {
    li n;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) cin >> arr[i];
    cout << Find1(arr, 0, n - 1) << endl;
    return 0;
}
#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Ceil(li arr[], li l, li r, li key) {
    if(key <= arr[l]) return l;
    if(key > arr[r]) return -1;

    li m = l + (r - l) / 2;
    if(key == arr[m]) return m;

    if(key < arr[m]) {
        if(m - 1 >= l && key >= arr[m - 1]) return m;
        else return Ceil(arr, l, m - 1, key);
    } else {
        if(m + 1 <= r && key <= arr[m + 1]) return m + 1;
        else return Ceil(arr, m + 1, r, key);
    }
}

li Floor(li arr[], li l, li r, li key) {
    if(l > r) return -1;
    if(key >= arr[r]) return r;

    li m = l + (r - l) / 2;
    if(key == arr[m]) return m;
    if(m >= 0 && key >= arr[m - 1] && key < arr[m]) return m - 1;

    if(key < arr[m]) return Floor(arr, l, m - 1, key);
    return Floor(arr, m + 1, r, key);
}

int main() {
    li n, key;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> key;
    cout << "Ceil: " << Ceil(arr, 0, n - 1, key) << endl;
    cout << "Floor: " << Floor(arr, 0, n - 1, key) << endl;
    return 0;
}
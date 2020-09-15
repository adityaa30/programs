#include <bits/stdc++.h>
#define li long long int
using namespace std;

li BinarySearch(li arr[], li l, li r, li x) {
    if (r >= l) {
        li mid = l + (r - l) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        if(arr[mid] > x) {
            return BinarySearch(arr, l, mid - 1, x);
        }
        return BinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    li ArraySize, X;
    cin >> ArraySize;
    li arr[ArraySize];
    for(li i = 0; i < ArraySize; ++i) {
        cin >> arr[i];
    }
    cin >> X;
    cout << BinarySearch(arr, 0, ArraySize - 1, X) << endl;
    return 0;
}
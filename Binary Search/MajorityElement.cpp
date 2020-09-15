#include <bits/stdc++.h>
#define li long long int
using namespace std;

li BinarySearchFirstOccurence(li arr[], li l, li r, li key) {
    if (r >= l) {
        li m = l + (r - l) / 2;
        
        if((m == 0 || arr[m - 1] < key) && arr[m] == key) return m;

        if(arr[m] >= key) return BinarySearchFirstOccurence(arr, l, m - 1, key);
        return BinarySearchFirstOccurence(arr, m + 1, r, key);
    }
    return -1;
}

bool IsMajorityElement(li arr[], li n, li key) {
    li pos = BinarySearchFirstOccurence(arr, 0, n - 1, key);
    
    if(pos == -1) return false;

    if((pos + n / 2) < n && arr[pos + n / 2] == key) return true;
    else return false;
}

int main() {
    li n, key;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> key;
    cout << IsMajorityElement(arr, n, key) << endl;
    return 0;
}
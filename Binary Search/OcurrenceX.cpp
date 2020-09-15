#include <bits/stdc++.h>
#define li long long int
using namespace std;

li FirstOccurence(li arr[], li l, li r, li key) {
    if(r >= l) {
        li m = l + (r - l) / 2;
        if((m == 0 || arr[m - 1] < key) && arr[m] == key) return m;
        if(key < arr[m]) return FirstOccurence(arr, l, m - 1, key);
        return FirstOccurence(arr, m + 1, r, key);
    }
    return -1;
}

li LastOccurence(li arr[], li l, li r, li key, li n) {
    if(r >= l) {
        li m = l + (r - l) / 2;
        if((m == n - 1 || arr[m + 1] > key) && arr[m] == key) return m;
        if(key < arr[m]) return LastOccurence(arr, l, m - 1, key, n);
        return LastOccurence(arr, m + 1, r, key, n);
    }
    return -1;
}

li OccurenceX(li arr[], li n, li key) {
    li first = FirstOccurence(arr, 0, n - 1, key);
    if(first == -1) return 0;

    li last = LastOccurence(arr, 0, n - 1, key, n);
    return last - first + 1;
}



int main() {
    li n, key;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> key;
    cout << "Occurence: " << OccurenceX(arr, n, key) << endl;
    return 0;
}
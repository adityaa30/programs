#include <bits/stdc++.h>
#define li long long int
using namespace std;

void MergeSorted(li arr1[], li n, li arr2[], li m, li arr[]) {
    li i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    while(i < n) arr[k++] = arr1[i++];
    while(j < m) arr[k++] = arr2[j++];
}

int main() {
    li n, m;
    cin >> n >> m;
    li arr1[n], arr2[m], arr3[n + m];
    for(li i = 0; i < n; ++i) cin >> arr1[i];
    for(li i = 0; i < m; ++i) cin >> arr2[i];
    MergeSorted(arr1, n, arr2, m, arr3);
    for(li i = 0; i < n + m; ++i) cout << arr3[i] << " ";
    cout << endl;
    return 0;
}
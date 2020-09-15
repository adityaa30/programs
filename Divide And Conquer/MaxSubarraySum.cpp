#include <bits/stdc++.h>
#include <limits.h>
#define li long long int
using namespace std;
 
li MaxSubarraySum(li arr[], li n) {
    li maxEndingHere = 0, maxSoFar = 0;
    for(li i = 0; i < n; ++i) {
        maxEndingHere = arr[i];
        if (maxEndingHere < 0) maxEndingHere = 0;
        if(maxSoFar < maxEndingHere) maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main() {
    li n;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) cin >> arr[i];
    cout << MaxSubarraySum(arr, n) << endl;
    return 0;
}
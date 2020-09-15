#include <bits/stdc++.h>
#define li long long int
using namespace std;

// Brian Kernighan's Algorithm
li CountSetBits(li n) {
    li count = 0;
    while(n > 0) {
        n &= n - 1;
        count++;
    }
    return count;
}

li FlippedCount(li a, li b) {
    return CountSetBits(a ^ b);
}

int main() {
    li n, m;
    cin >> n >> m;
    cout << FlippedCount(n, m) << endl;
    return 0;
}
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

int main() {
    li n;
    cin >> n;
    cout << CountSetBits(n) << endl;
    return 0;
}
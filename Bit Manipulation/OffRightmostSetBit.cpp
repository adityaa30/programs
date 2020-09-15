#include <bits/stdc++.h>
#define li long long int
using namespace std;

li OffRightmostSetBit(li n) {
    return n & (n - 1);
}

int main() {
    li n;
    cin >> n;
    cout << OffRightmostSetBit(n) << endl;
    return 0;
}
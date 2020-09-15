#include <bits/stdc++.h>
#define li long long int
using namespace std;

bool IsPowerOf2(li n) {
    return n && !(n & (n - 1));
}

// To calculate the total number of bits in GCC compiler use: __builtin_popcount()

int main() {
    li n;
    cin >> n;
    cout << IsPowerOf2(n) << endl;
    return 0;
}
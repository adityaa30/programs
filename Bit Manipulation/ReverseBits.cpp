#include <bits/stdc++.h>
#define li long long int

#define R2(n) n, n + 2*64, n + 1*64, n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4), R4(n + 1*4), R4(n + 3*4)

using namespace std;

unsigned li lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };

li ReverseBits(li n) {
    return lookuptable[n & 0xff] << 24 |
            lookuptable[(n >> 8) & 0xff] << 16 |
            lookuptable[(n >> 16) & 0xff] << 8 |
            lookuptable[(n >> 24) & 0xff];
}

int main() {
    li n;
    cin >> n;
    cout << ReverseBits(n) << endl;
}
#include <bits/stdc++.h>

#define uli unsigned long int
#define li long int
using namespace std;

uli getUglyNo(uli n) {
    uli ugly[n];
    uli i2 = 0, i3 = 0, i5 = 0;
    uli next_multiple_2 = 2;
    uli next_multiple_3 = 3;
    uli next_multiple_5 = 5;
    uli next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
        next_ugly_no = min(next_multiple_2, min(next_multiple_3, next_multiple_5));
        ugly[i] = next_ugly_no;

        if (next_ugly_no == next_multiple_2)
            next_multiple_2 = ugly[++i2] * 2;

        if (next_ugly_no == next_multiple_3)
            next_multiple_3 = ugly[++i3] * 3;

        if (next_ugly_no == next_multiple_5)
            next_multiple_5 = ugly[++i5] * 5;
    }
    return next_ugly_no;
}

int main() {
    uli n;
    cin >> n;
    cout << getUglyNo(n) << endl;
}
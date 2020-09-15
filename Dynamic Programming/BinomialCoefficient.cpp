#include <bits/stdc++.h>
#define uli unsigned long int
using namespace std;

uli nCr(uli n, uli r) {
    uli C[n + 1][r + 1];
    for (uli i = 0; i <= n; ++i)
        for(uli j = 0; j <= min(i, r); ++j) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    return C[n][r];
}

int main() {
    uli n, r;
    cin >> n >> r;
    if (r == 0 || n == r)
        cout << '1' << endl;
    else
        cout << nCr(n, r) << endl;
    return 0;
}
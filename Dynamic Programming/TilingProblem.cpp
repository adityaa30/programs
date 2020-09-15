#include <bits/stdc++.h>
#define uli unsigned long int
using namespace std;

uli count(uli n) {
    uli dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (uli i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    uli n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}
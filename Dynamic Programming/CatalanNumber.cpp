#include <bits/stdc++.h>
#define uli unsigned long int
using namespace std;

uli catalanNumber(uli n) {
    uli catalan[n + 1] = { 0 };
    catalan[0] = catalan[1] = 1;

    for (uli i = 2; i <= n; ++i)
        for(uli j = 0; j < i; ++j)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    
    return catalan[n];
}

int main() {
    uli n;
    cin >> n;
    cout << catalanNumber(n) << endl;
    return 0;
}
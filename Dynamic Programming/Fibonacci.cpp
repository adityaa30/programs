#include <bits/stdc++.h>

#define uli unsigned long int
using namespace std;

uli fibonacci(uli n) {
    uli fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;

    for (uli i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

int main() {
    uli n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}
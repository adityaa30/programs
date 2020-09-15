#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Fibonacci(li n) {
    if(n <= 1) return n;
    else return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    li n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    
    // First 10 fibonacci numbers
    for(li i = 1; i <= 10; ++i) 
        cout << Fibonacci(i) << " ";
    cout << endl;
    
    return 0;
}
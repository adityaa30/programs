#include <bits/stdc++.h>
#define li long long int
using namespace std;

li SwapEvenOddBits(li n) {
    unsigned li evenDigits = n & 0xAAAAAAAA; 
    unsigned li oddDigits = n & 0x55555555;

    evenDigits = evenDigits >> 1;
    oddDigits = oddDigits << 1;
    return (evenDigits | oddDigits); 
}


int main() {
    li n;
    cin >> n;
    cout << SwapEvenOddBits(n) << endl;
}

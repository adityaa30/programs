#include <bits/stdc++.h>
#define li long long int
using namespace std;

bool PowerOf2(li n) {
    return n > 0 && !(n & (n - 1));
}

int GetPosOnlySetBit(li n) {
    if (!PowerOf2(n)) return -1;
    return log2(n) + 1;
}

int main() {
    li n;
    cin >> n;
    cout << GetPosOnlySetBit(n) << endl;
    return 0;
}
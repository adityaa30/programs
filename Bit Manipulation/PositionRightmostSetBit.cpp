#include <bits/stdc++.h>
#define li long long int
using namespace std;

li GetPositionRightmostSetBit(li n) {
    return log2(n & -n) + 1;
}

int main() {
    li n;
    cin >> n;
    cout << GetPositionRightmostSetBit(n) << endl;
    return 0;
}
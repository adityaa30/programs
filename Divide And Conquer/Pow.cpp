#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Pow(li x, li y) {
    if(y == 0) return 1;
    li temp = Pow(x, y / 2);
    if(y % 2 == 0) return temp * temp;
    else return temp * temp * x;
}

li ModPow(li x, li y, li m) {   
    li res = 1;
    x = x % m;
    while(y > 0) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y = y >> 1;
    }
    return res;
}

int main() {
    li x, y;
    cin >> x >> y;
    cout << Pow(x, y) << endl;
    cout << ModPow(x, y, 10) << endl;
    return 0;
}
 
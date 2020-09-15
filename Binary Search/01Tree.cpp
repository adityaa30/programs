#include <bits/stdc++.h>
#define li long long int
using namespace std;

li Find(li N, li k) {
    if(N == 0) return 0;
    if(k <= pow(2, N - 1)) return Find(N-1, k);
    else return !Find(N-1, k - pow(2, N - 1)); 
}

int main() {
    li k, n;
    cin >> n;
    for(li i = 1; i <= 16; ++i) cout << Find(n, i) << ' '; 
}

// Game of Maximization
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  scanf("%d", &n);
  int odd = 0, even = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if ((i % 2) == 0) {
      even += x;
    } else {
      odd += x;
    }
  }
  int ans = min(odd, even);
  ans *= 2;
  printf("%d\n", ans);
  return 0;
}
// Strictly Increasing Sequence
#include <bits/stdc++.h>
using namespace std;
    
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      s.insert(x);
    }
    if (s.size() == n || (n % 2 == 1)) {
      printf("First\n");
    } else {
      printf("Second\n");
    }
  }

  return 0;
}
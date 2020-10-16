// RBG Queries
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  array<map<int, set<array<int, 3>>>, 3> RGB;
  set<array<int, 3>> fix;
  for (int i = 0; i < n; ++i) {
    array<int, 3> color;
    scanf("%d %d %d", &color[0], &color[1], &color[2]);
    if (fix.find(color) == fix.end()) {
      for (int k = 0; k < 3; ++k) RGB[k][color[k]].insert(color);
      fix.insert(color);
    }
  }

  while (q--) {
    array<int, 3> color;
    scanf("%d %d %d", &color[0], &color[1], &color[2]);
    int cnt = 0;
    for (int k = 0; k < 3; ++k) {
      for (auto curr : RGB[k][color[k]]) {
        if (curr[0] <= color[0] && curr[1] <= color[1] && curr[2] <= color[2]) {
          ++cnt;
          break;
        }
      }
      if (cnt != (k + 1)) {
        break;
      }
    }
    if (cnt == 3) printf("YES\n");
    else printf("NO\n");
  }

  return 0;
}
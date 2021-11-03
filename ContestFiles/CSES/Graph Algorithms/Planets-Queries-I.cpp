#include <bits/stdc++.h>
using namespace std;

const int MAX_JUMPS_LOGN = 30;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> nxt(MAX_JUMPS_LOGN, vector<int>(n, -1));

  for (int i = 0; i < n; ++i) {
    cin >> nxt[0][i];
    --nxt[0][i];
  }

  for (int k = 1; k < MAX_JUMPS_LOGN; ++k) {
    for (int i = 0; i < n; ++i) {
      if (nxt[k - 1][i] != -1) {
        nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
      }
    }
  }

  auto get = [&](int start, int jumps) {
    int curr = start;
    for (int bit = MAX_JUMPS_LOGN - 1; bit >= 0; --bit) {
      if ((1 << bit) & jumps) {
        curr = nxt[bit][curr];
      }
    }

    return curr;
  };

  for (int i = 0; i < q; ++i) {
    int a, k;
    cin >> a >> k;
    cout << (1 + get(a - 1, k)) << '\n';
  }

  return 0;
}
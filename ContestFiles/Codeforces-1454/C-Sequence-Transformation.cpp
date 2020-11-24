#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }

  int ans = INT_MAX;
  for (auto [x, pos] : adj) {
    int c = 0;
    int prev = -1;
    for (int p : pos) {
      if (p != prev + 1) {
        ++c;
      }
      prev = p;
    }
    if (prev != n - 1) {
      ++c;
    }
    ans = min(c, ans);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve();
  }

  return 0;
}
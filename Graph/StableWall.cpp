// adityaa30
// Google Kickstart Round C 2020
// Problem: Stable Wall
#include <bits/stdc++.h>
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    int R, C;
    cin >> R >> C;
    vector<string> wall(R);
    set<char> keys;
    vector<set<int>> adj(26, set<int>());
    for (int i = 0; i < R; ++i) {
      cin >> wall[i];
      for (auto x : wall[i])
        keys.insert(x);

      if (i > 0)
        for (int j = 0; j < C; ++j)
          if (wall[i - 1][j] != wall[i][j])
            adj[wall[i - 1][j] - 'A'].insert(wall[i][j] - 'A');
    }
    vector<int> visited(26, false);
    vector<int> onCurrPath(26, false);
    bool cycle = false;
    string ans = "";
    function<void(int)> topoSort = [&](int curr) {
      visited[curr] = true;
      onCurrPath[curr] = true;
      for (auto child : adj[curr]) {
        if (onCurrPath[child]) {
          cycle = true;
          return;
        } else if (!visited[child]) {
          topoSort(child);
        }
      }
      onCurrPath[curr] = false;
      ans += char(curr + 'A');
    };

    for (auto c : keys) {
      if (!visited[c - 'A'])
        topoSort(c - 'A');
    }

    if (cycle) {
      cout << "Case #" << test << ": -1\n";
    } else {
      cout << "Case #" << test << ": " << ans << "\n";
    }
  }

  return 0;
}
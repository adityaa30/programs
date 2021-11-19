#include <bits/stdc++.h>
using namespace std;

const int IN_CYCLE = -100;

int32_t main() {
  int n;
  cin >> n;

  vector<int> nxt(n, -1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nxt[i] = x - 1;
  }

  vector<bool> in_path(n, false);
  vector<int> ans(n, -1), path;
  function<void(int)> go = [&](int curr) {
    path.push_back(curr);
    in_path[curr] = true;

    if (ans[nxt[curr]] != -1) {
      // we know the ans the to the next one. so we just add 1 to it as 
      // one step is required to reach it.
      ans[curr] = ans[nxt[curr]] + 1;

    } else if (!in_path[nxt[curr]]) {
      go(nxt[curr]);
      if (ans[curr] == -1 && ans[nxt[curr]] != -1) {
        ans[curr] = ans[nxt[curr]] + 1;
      }

    } else {
      // nxt point is already visited. so we are inside a loop at nxt[curr]
      reverse(path.begin(), path.end());
      bool cycle_end = false;
      int cycle_size = 0;
      for (int i = 0; i < path.size(); ++i) {
        if (!cycle_end) {
          ++cycle_size;
          cycle_end = cycle_end || (path[i] == nxt[curr]);
          ans[path[i]] = IN_CYCLE;
        } else {
          ans[path[i]] = i + 1;
        }
      }

      for (int x : path) {
        ans[x] = (ans[x] == IN_CYCLE ? cycle_size : ans[x]);
      }
      reverse(path.begin(), path.end());
    }
    path.pop_back();
    in_path[curr] = false;
  };

  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) {
      go(i);
    }
    cout << ans[i] << ' ';
  }
  cout << '\n';


  return 0;
}
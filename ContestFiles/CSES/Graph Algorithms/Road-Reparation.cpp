#include <bits/stdc++.h>
#define int long long int
using namespace std;

class DSU {
private:
  vector<int> parent, rank;

public:
  DSU(int sz) {
    parent = vector<int>(sz + 1);
    rank = vector<int>(sz + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int Root(int x) {
    if (parent[x] != x) {
      parent[x] = Root(parent[x]);
    }
    return parent[x];
  }

  bool Union(int x, int y) {
    int r_x = Root(x), r_y = Root(y);

    if (r_x == r_y) {
      return false;
    } else if (rank[r_x] == rank[r_y]) {
      rank[r_x]++;
    } else if (rank[r_x] < rank[r_y]) {
      swap(x, y);
      swap(r_x, r_y);
    }

    parent[r_y] = r_x;
    return true;
  }
};

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> E(m);
  for (int i = 0; i < m; ++i) {
    cin >> E[i][0] >> E[i][1] >> E[i][2];
  }

  sort(E.begin(), E.end(), [](const array<int, 3> &A, const array<int, 3> &B) {
    return A[2] < B[2];
  });

  DSU dsu(n + 1);
  int total = 0, components = n;
  for (auto [a, b, w] : E) {
    if (dsu.Union(a, b)) {
      total += w;
      --components;
    }
  }

  if (components == 1) {
    cout << total << '\n';
  } else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}
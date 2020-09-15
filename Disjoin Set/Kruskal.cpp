// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
#define print(it)                                                              \
  cout << #it << ' -> ';                                                       \
  for (auto __x__ : it)                                                        \
    cout << __x__ << ' ';                                                      \
  cout << '\n';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1, 1, 1, -1, -1};
int PosY[] = {1, 0, -1, 0, 1, -1, 1, -1};

class DSUWeighted {
private:
  vector<int> parent, size;

public:
  DSUWeighted(int n) {
    this->size = vector<int>(n + 5, 1);
    this->parent = vector<int>(n + 5, 0);
    for (int i = 0; i <= n; ++i) {
      this->parent[i] = i;
    }
  }

  int Root(int x) {
    while (parent[x] != x) {
      x = parent[x];
    }
    return x;
  }

  bool Find(int x, int y) { return (Root(x) == Root(y)); }

  void Union(int x, int y) {
    int rootX = Root(x), rootY = Root(y);
    if (size[rootX] < size[rootY]) {
      parent[rootX] = parent[rootY];
      size[rootY] += size[rootX];
    } else {
      parent[rootY] = parent[rootX];
      size[rootX] += size[rootY];
    }
  }

  int Size(int x) { return this->size[Root(x)]; }
};

struct Edge {
  int from, to, weight;
};

vector<Edge> KruskalMST(int v, vector<Edge> edges) {
  sort(edges.begin(), edges.end(),
       [](Edge &a, Edge &b) { return a.weight < b.weight; });

  DSUWeighted dsu(v);

  vector<Edge> ans;
  for (Edge e : edges) {
    if (!dsu.Find(e.from, e.to)) {
      dsu.Union(e.from, e.to);
      edges.push_back(e);
    }
  }

  return edges;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
  }

  return 0;
}
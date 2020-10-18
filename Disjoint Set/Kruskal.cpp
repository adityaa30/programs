// adityaa30
#include "DSUWeighted.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1000000007;
struct Edge {
  int from, to, weight;
};

vector<Edge> KruskalMST(int v, vector<Edge> edges) {
  sort(edges.begin(), edges.end(),
       [](Edge &a, Edge &b) { return a.weight < b.weight; });

  DSUWeighted dsu(v);

  vector<Edge> ans;
  for (Edge e : edges) {
    if (dsu.Union(e.from, e.to)) {
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
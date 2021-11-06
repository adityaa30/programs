#include <KosarajuSCC.hpp>
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int m, n;
  cin >> m >> n;

  auto Abs = [&](int x) {
    if (x >= n) {
      return (x - n);
    }
    return x;
  };

  auto Negate = [&](int x) {
    if (x >= n) {
      return (x - n);
    }
    return x + n;
  };

  vector<vector<int>> adj(2 * n);
  for (int i = 0; i < m; ++i) {
    char t_a, t_b;
    int a, b;
    cin >> t_a >> a >> t_b >> b;
    --a, --b;

    if (t_a == '-') {
      a += n;
    }
    if (t_b == '-') {
      b += n;
    }

    adj[Negate(a)].push_back(b);
    adj[Negate(b)].push_back(a);
  }

  KosarajuSCC scc(adj);

  for (int i = 0; i < n; ++i) {
    // Nodes in the same node is a contradiction
    if (scc.group[i] == scc.group[i + n]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  auto compressed_topo = scc.topo_sort(scc.compressed_adj, true);
  vector<char> category(n, '?');

  vector<vector<int>> group_nodes(scc.num_components);
  for (int i = 0; i < 2 * n; ++i) {
    group_nodes[scc.group[i]].push_back(i);
  }

  for (int compressed_node : compressed_topo) {
    for (int x : group_nodes[compressed_node]) {
      if (category[Abs(x)] == '?') {
        category[Abs(x)] = (x >= n ? '-' : '+');
      }
    }
  }

  for (char c : category) {
    cout << c << ' ';
  }
  cout << '\n';

  return 0;
}
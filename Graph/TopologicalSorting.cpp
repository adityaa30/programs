// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

void TopoSort(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);

  bool isCycle = false;
  stack<int> s;
  function<void(int)> Util = [&](int curr) {
    visited[curr] = true;
    for (int child : adj[curr]) {
      if (!visited[child]) {
        Util(child);
      }
    }
    s.push(curr);
  };

  for (int i = 0; i < V; ++i) {
    if (!visited[i])
      Util(i);
  }

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  // Take input of a graph having V vertices & E edges
  int V, E, a, b;
  cin >> V >> E;
  vector<vector<int>> adj(V, vector<int>());
  for (int i = 0; i < E; ++i) {
    // (a, b) are 0-indexed
    cin >> a >> b;
    adj[a].push_back(b);
  }

  vector<bool> visited(V, false), onCurrPath(V, false);
  vector<int> order;
  bool cycle = false;
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
    order.emplace_back(curr);
  };

  for (int i = 0; i < V; ++i) {
    if (!visited[i])
      topoSort(i);
  }

  if (cycle) {
    cout << "Graph has a cyle\n";
  } else {
    reverse(order.begin(), order.end());
    cout << "Topological Order: ";
    for (auto x : order) {
      cout << x << " ";
    }
  }

  return 0;
}
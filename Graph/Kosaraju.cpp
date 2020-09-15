// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

stack<int> TopoSort(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);

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

  return s;
}

vector<vector<int>> Transpose(vector<vector<int>> &adj) {
  vector<vector<int>> transpose(adj.size());
  for (int parent = 0; parent < adj.size(); ++parent) {
    for (int child : adj[parent]) {
      transpose[child].push_back(parent);
    }
  }

  return transpose;
}

void ShowSCC(vector<vector<int>> &adj) {
  stack<int> topo = TopoSort(adj);
  vector<vector<int>> tranpose = Transpose(adj);

  vector<int> visited(adj.size(), false);
  function<void(int)> PrintSCC = [&](int curr) {
    cout << curr << " ";
    visited[curr] = true;
    for (int child : tranpose[curr]) {
      if (!visited[child]) {
        PrintSCC(child);
      }
    }
  };

  while (!topo.empty()) {
    int top = topo.top(); topo.pop();
    if (!visited[top]) PrintSCC(top);
    cout << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  // Take input of a graph having V vertices & E edges
  int V = 5;
  vector<vector<int>> adj(V);

  function<void(int, int)> addEdge = [&](int a, int b) {
    adj[a].push_back(b);
  };

  addEdge(1, 0);
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(2, 1);
  addEdge(3, 4);

  ShowSCC(adj);

  return 0;
}
#pragma once
#include <bits/stdc++.h>
using namespace std;

class KosarajuSCC {
public:
  static vector<int> topo_sort(vector<vector<int>> &graph,
                               bool reversed = false) {
    int sz = graph.size();
    vector<int> order;
    vector<bool> visited(sz, false);
    function<void(int)> dfs = [&](int curr) {
      visited[curr] = true;
      for (int child : graph[curr]) {
        if (!visited[child]) {
          dfs(child);
        }
      }

      order.push_back(curr);
    };

    for (int i = 0; i < sz; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }

    assert((int)order.size() == sz);
    if (!reversed) {
      reverse(order.begin(), order.end());
    }

    return order;
  }

public:
  vector<int> group;
  vector<vector<int>> adj, rev_adj, compressed_adj;
  int n, num_components;

  KosarajuSCC(vector<vector<int>> &adj) : adj(adj) {
    this->n = adj.size();
    rev_adj = vector<vector<int>>(n);

    for (int from = 0; from < n; ++from) {
      for (int to : adj[from]) {
        rev_adj[to].push_back(from);
      }
    }

    this->group = vector<int>(n, -1);
    function<void(int, int)> mark = [&](int curr, int what) {
      group[curr] = what;
      for (int child : rev_adj[curr]) {
        if (group[child] == -1) {
          mark(child, what);
        }
      }
    };

    auto rev_topo = topo_sort(this->adj);
    this->num_components = 0;

    for (int x : rev_topo) {
      if (group[x] == -1) {
        mark(x, this->num_components++);
      }
    }

    // Build the compressed_adj
    compressed_adj = vector<vector<int>>(num_components);
    for (int from = 0; from < n; ++from) {
      for (int to : adj[from]) {
        compressed_adj[group[from]].push_back(group[to]);
      }
    }

    // remove dumplicates from `compressed_adj`
    for (int i = 0; i < num_components; ++i) {
      unordered_set<int> unique_vals(compressed_adj[i].begin(),
                                     compressed_adj[i].end());

      // Remove the self-cycle node if exits
      unique_vals.erase(i);
      compressed_adj[i] = vector<int>(unique_vals.begin(), unique_vals.end());
    }
  }
};

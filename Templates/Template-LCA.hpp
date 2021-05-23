#pragma once
#include "./Template.hpp"
#include <bits/stdc++.h>
using namespace std;

class BinaryLiftLCA : BinaryLift {
protected:
  vector<int> tin, tout;

private:
  void init(vector<vector<int>> &adj, int root) {
    int timer = 0;

    /**
     * Here there is no concept of NO_PARENT.
     * If a node do not have a parent after x jumps
     * then it's parent is assinged as root.
     * Refer: https://cp-algorithms.com/graph/lca_binary_lifting.html
     */

    function<void(int, int)> dfs = [&](int curr, int parent) {
      up[curr][0] = parent;
      tin[curr] = ++timer;

      for (int i = 1; i <= limit; ++i) {
        up[curr][i] = up[up[curr][i - 1]][i - 1];
      }

      for (int child : adj[curr]) {
        if (child != parent) {
          dfs(child, curr);
        }
      }

      tout[curr] = ++timer;
    };

    dfs(root, root);
  }

  bool IsAncestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
  }

public:
  BinaryLiftLCA(vector<vector<int>> &adj, int root = 0)
      : BinaryLift(adj, root) {
    tin = vector<int>(n);
    tout = vector<int>(n);

    init(adj, root);
  }

  int LCA(int u, int v) {
    if (IsAncestor(u, v)) {
      return u;
    }

    if (IsAncestor(v, u)) {
      return v;
    }

    for (int i = limit; i >= 0; --i) {
      if (!IsAncestor(up[u][i], v)) {
        u = up[u][i];
      }
    }

    return up[u][0];
  }
};

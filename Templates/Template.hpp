#pragma once
#include <bits/stdc++.h>
using namespace std;

class BinaryLift {
public:
  const int NO_PARENT = -1;

protected:
  int limit; // Inclusive
  int n;     // Number of Nodes
  vector<vector<int>> up;

private:
  void init(vector<vector<int>> &adj, int root) {
    function<void(int, int)> dfs = [&](int curr, int parent) {
      up[curr][0] = parent;

      for (int i = 1; i <= limit; ++i) {
        if (up[curr][i - 1] != NO_PARENT) {
          up[curr][i] = up[up[curr][i - 1]][i - 1];
        } else {
          break;
        }
      }

      for (int child : adj[curr]) {
        if (child != parent) {
          dfs(child, curr);
        }
      }
    };

    dfs(root, NO_PARENT);
  }

public:
  BinaryLift(vector<vector<int>> &adj, int root = 0) {
    this->n = adj.size(); // Number of nodes
    assert(0 <= root && root < n);

    this->limit = (int)ceil(log2(n));
    up = vector<vector<int>>(n, vector<int>(limit + 1, NO_PARENT));

    init(adj, root);
  }

  int Parent(int idx, int jump) {
    assert(0 <= idx && idx < this->n);
    assert(0 <= jump);

    if (jump > (1 << this->limit)) {
      return NO_PARENT;
    }

    // Iterate over the bits in `jump`
    for (int i = limit; i >= 0 && idx != NO_PARENT; --i) {
      if (jump & (1LL << i)) {
        idx = up[idx][i];
      }
    }

    return idx;
  }

  friend std::ostream &operator<<(std::ostream &os, const BinaryLift &lift) {
    os << "Jumps:\tNodes\n";
    os << "0:\t";
    for (int i = 0; i < lift.n; ++i) {
      os << i << '\t';
    }

    for (int i = 0; i <= lift.limit; ++i) {
      os << "\n" << (i + 1) << ":\t";
      for (int j = 0; j < lift.n; ++j) {
        os << lift.up[j][i] << '\t';
      }
    }
    os << '\n';
    return os;
  }

  vector<int> &operator[](int index) { return up[index]; }
};

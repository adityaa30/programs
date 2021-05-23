#include <bits/stdc++.h>
using namespace std;

class DSURank {
private:
  vector<int> parent, rank;

public:
  DSURank(int N) {
    rank = vector<int>(N + 1, 0);
    parent = vector<int>(N + 1, 0);
    iota(parent.begin(), parent.end(), 0);
  }

  int Root(int x) {
    // Apply path compression
    if (parent[x] != x) {
      parent[x] = Root(parent[x]);
    }
    return parent[x];
  }

  bool Union(int x, int y) {
    int rootX = Root(x), rootY = Root(y);
    if (rootX == rootY)
      return false;

    if (rank[rootX] == rank[rootY]) {
      rank[rootX]++;
    }
    if (rank[rootX] > rank[rootY]) {
      swap(rootX, rootY);
    }

    // rank[rootX] < rank[rootY]
    parent[rootX] = rootY;
    return true;
  }
};

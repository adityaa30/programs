#include <bits/stdc++.h>
using namespace std;

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

  bool Union(int x, int y) {
    int rootX = Root(x), rootY = Root(y);
    if (rootX == rootY)
      return false;

    if (size[rootX] < size[rootY]) {
      parent[rootX] = rootY;
      size[rootY] += size[rootX];
    } else {
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
    }
    return true;
  }

  int Size(int x) { return this->size[Root(x)]; }
};
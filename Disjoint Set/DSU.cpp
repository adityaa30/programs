#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> parent;

public:
  DSU(int n) { this->parent = vector<int>(n + 5, -1); }

  int Root(int x) {
    while (parent[x] != -1) {
      x = parent[x];
    }
    return x;
  }

  bool Union(int x, int y) {
    int rootX = Root(x), rootY = Root(y);
    if (rootX != rootY) {
      parent[rootX] = rootY;
      return true;
    }
    return false;
  }
};

int main() { return 0; }
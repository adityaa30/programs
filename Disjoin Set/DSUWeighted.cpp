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

  bool Find(int x, int y) { return (Root(x) == Root(y)); }

  void Union(int x, int y) {
    int rootX = Root(x), rootY = Root(y);
    if (size[rootX] < size[rootY]) {
      parent[rootX] = parent[rootY];
      size[rootY] += size[rootX];
    } else {
      parent[rootY] = parent[rootX];
      size[rootX] += size[rootY];
    }
  }

  int Size(int x) { return this->size[Root(x)]; }
};

int main() { return 0; }
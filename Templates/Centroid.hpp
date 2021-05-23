#include <bits/stdc++.h>
using namespace std;

vector<int> GetTreeCentroids(vector<vector<int>> &adj) {
  /*
  Centroid of a Tree is a node which if removed from the tree would split
  it into a ‘forest’, such that any tree in the forest would have at most
  half the number of vertices in the original tree.
  */

  int n = (int)adj.size(); // 0-Indexed Undirectee Tree

  vector<int> centroids;
  int mx = 0;

  function<int(int, int)> dfs = [&](int curr, int parent) {
    int size = 1, mxSize = 1;
    for (int child : adj[curr]) {
      if (child != parent) {
        int sz = dfs(child, curr);
        mxSize = max(mxSize, sz);
        size += sz;
      }
    }
    mxSize = max(mxSize, n - size);
    if (mxSize > mx) {
      mx = mxSize;
      centroids.clear();
      centroids.push_back(curr);
    } else if (mxSize == mx) {
      centroids.push_back(curr);
    }

    return size;
  };

  dfs(0, -1);
  return centroids;
}

// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

struct Node {
  int mxSum, mxSuffix, mxPrefix, sum;
};

void Solve(int test) {
  int N, M;
  cin >> N >> M;
  vector<Node> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i].sum;
    arr[i].mxPrefix = max(0ll, arr[i].sum);
    arr[i].mxSuffix = max(0ll, arr[i].sum);
    arr[i].mxSum = max(0ll, arr[i].sum);
  }

  auto Merge = [](Node &x, Node &y) {
    Node n;
    n.sum = x.sum + y.sum;
    n.mxSum = max({x.mxSum, y.mxSum, x.mxSuffix + y.mxPrefix});
    n.mxPrefix = max(x.mxPrefix, x.sum + y.mxPrefix);
    n.mxSuffix = max(y.mxSuffix, y.sum + x.mxSuffix);
    return n;
  };

  SegmentTree<Node> st(arr, {0, 0, 0, 0}, Merge);
  Node res = st.Query(0, N);
  cout << res.mxSum << '\n';
  for (int query = 1; query <= M; ++query) {
    int idx, val;
    cin >> idx >> val;
    st.Set(idx, {max(0ll, val), max(0ll, val), max(0ll, val), val});
    res = st.Query(0, N - 1);
    cout << res.mxSum << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve(test);
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define vi vector<ll>
const long long mod = 1000000007LL;

#define ff first
#define ss second
#define pi pair<ll, ll>
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e18;

inline int max(int a, int32_t b) { return a > b ? a : b; }
inline int max(int32_t a, int b) { return a > b ? a : b; }
inline int min(int a, int32_t b) { return a < b ? a : b; }
inline int min(int32_t a, int b) { return a < b ? a : b; }
int d4_1[4] = {1, 0, -1, 0};
int d4_2[4] = {0, 1, 0, -1};
int d8_1[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int d8_2[8] = {0, -1, 1, 0, -1, 1, 1, -1};


class edge {
public:
  int a, b, c, index;
};
vi parent;
vi size_tree;

int get(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = get(parent[x]);
}

bool union_find(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) {
    return true;
  }
  if (size_tree[b] > size_tree[a]) {
    swap(a, b);
  }
  parent[b] = a;
  size_tree[a] += size_tree[b];
  return false;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<edge> v;
  int total = 0;
  for (int i = 0; i < m; i++) {
    edge e;
    cin >> e.a >> e.b >> e.c;
    e.index = i + 1;
    v.pb(e);
    total += e.c;
  }
  sort(all(v), [](edge a, edge b) { return a.c > b.c; });
  int ans = inf;
  parent = vi(n + 1);
  iota(all(parent), 0);
  size_tree = vi(n + 1, 1);
  vector<edge> delete_edge;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    if (union_find(v[i].a, v[i].b)) {
      sum += v[i].c;
      delete_edge.pb(v[i]);
    }
  }
  reverse(all(delete_edge));
  vi index;
  for (int i = 0; i < delete_edge.size(); i++) {
    k -= delete_edge[i].c;
    if (k >= 0) {
      index.pb(delete_edge[i].index);
    }
  }
  sort(all(index));
  cout << index.size() << "\n";
  for (auto i : index)
    cout << i << " ";
  cout << "\n";
}

int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);

  ll t = 1;
  // cin>>t;

  for (int i = 1; i <= t; i++) {
    // cout<<"Case "<<i<<": ";
    solve();
  }
}
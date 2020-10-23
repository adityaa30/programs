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

class edge {
public:
  int a, b, c;
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
  int n, m;
  cin >> n >> m;
  vector<edge> v;
  for (int i = 0; i < m; i++) {
    edge e;
    cin >> e.a >> e.b >> e.c;
    v.pb(e);
  }
  
  sort(all(v), [](edge a, edge b) { return a.c < b.c; });
  parent = vi(n + 1);
  iota(all(parent), 0);
  int ans = 0;

  size_tree = vi(n + 1, 1);
  for (int i = 0; i < m; i++) {
    if (!union_find(v[i].a, v[i].b)) {
      ans += v[i].c;
    }
  }
  cout << ans << "\n";
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
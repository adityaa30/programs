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


vi max_ele;
vi parent;

int get(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = get(parent[x]);
}

void union_find(int a, int b) {
  a = get(a);
  b = get(b);
  if (max_ele[b] > max_ele[a]) {
    swap(a, b);
  }
  parent[b] = a;
  max_ele[b] = max(max_ele[a], max_ele[b]);
}

vi v;
int n;
int calc(int x) {
  if (v[x] == 0) {
    if (x != 1 && v[x - 1] == 1) {
      union_find(x, x - 1);
    }
    if (x < n && v[x + 1] == 1) {
      union_find(x, x + 1);
    }
    v[x] = 1;
    return x;
  }
  int pos = get(x);
  if (pos == n) {
    return calc(1);
  } else {
    return calc(pos + 1);
  }
}

void solve() {
  cin >> n;
  v = vi(n + 1, 0);
  max_ele = vi(n + 1);
  iota(all(max_ele), 0);
  parent = vi(n + 1);
  iota(all(parent), 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << calc(x) << " \n"[i == n - 1];
  }
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
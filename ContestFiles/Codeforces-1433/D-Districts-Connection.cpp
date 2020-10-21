#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    s.insert(A[i]);
  }
  if (s.size() == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  auto it = s.begin();
  vector<int> ans(n);
  int first = *it;
  it++;
  int second = *it;
  pair<int, int> nums = {first, second};
  for (int i = 0; i <= n; ++i) {
    if (first == A[i]) {
      first = i + 1;
      A[i] = -1;
      break;
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (second == A[i]) {
      second = i + 1;
      A[i] = -1;
      break;
    }
  }
  cout << first << ' ' << second << '\n';
  for (int i = 0; i < n; ++i) {
    if (A[i] == -1)
      continue;
    if (A[i] == nums.first) {
      cout << second << ' ' << i + 1 << '\n';
    } else {
      cout << first << ' ' << i + 1 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve();
  }

  return 0;
}
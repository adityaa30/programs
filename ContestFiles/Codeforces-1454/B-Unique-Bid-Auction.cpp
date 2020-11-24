#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<array<int, 2>> A(n);
  unordered_map<int, int> count;
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0];
    count[A[i][0]]++;
    A[i][1] = i;
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < n; ++i) {
    if (count[A[i][0]] == 1) {
      cout << A[i][1] + 1 << '\n';
      return;
    }
  }
  cout << "-1\n";
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
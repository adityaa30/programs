#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int n, k, s;
  cin >> n >> k >> s;
  cout << min(k + n, k -1 + k - s + n - s + 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ": ";
    Solve(test);
  }

  return 0;
}
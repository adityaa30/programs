#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  for (int i = 0; i < N; ++i) X[i] -= i;
  sort(X.begin(), X.end());
  int ans = 0;
  int mx = X[N/2], my = Y[N/2];
  for (int i = 0; i < N; ++i) {
    ans += abs(X[i] - mx) + abs(Y[i] - my);
  }
  cout << ans << '\n';
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
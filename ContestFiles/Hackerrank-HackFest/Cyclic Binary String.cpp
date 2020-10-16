// Cyclic Binary String
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S;
  cin >> S;
  S += S;
  int ans = 0, now = 0;
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == '0') {
      ++now;
    } else {
      ans = max(ans, now);
      now = 0;
    }
  }
  ans = max(ans, now);
  cout << (ans == S.length() ? -1 : ans) << '\n';

  return 0;
}
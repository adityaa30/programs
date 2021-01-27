
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<array<int, 2>> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0];
    A[i][1] = i + 1;
  }

  sort(A.begin(), A.end());
  for (int i = 0; i < n - 2; ++i) {
    int target = x - A[i][0];
    int left = i + 1, right = n - 1;
    while (left < right) {
      int s = A[left][0] + A[right][0];
      if (s == target) {
        cout << A[i][1] << ' ' << A[left][1] << ' ' << A[right][1] << '\n';
        return 0;
      } else if (s < target) {
        ++left;
      } else if (s > target) {
        --right;
      }
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}
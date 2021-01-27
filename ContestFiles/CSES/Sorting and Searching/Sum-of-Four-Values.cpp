#include <bits/stdc++.h>
using namespace std;

bool ok(array<int, 3> &a, array<int, 3> &b) {
  set<int> s;
  s.insert(a[1]);
  s.insert(a[2]);
  s.insert(b[1]);
  s.insert(b[2]);
  return s.size() == 4;
}

int32_t main() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int &a : A) cin >> a;

  vector<array<int, 3>> arr;
  arr.reserve((n * (n - 1)) / 2);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      arr.push_back({A[i] + A[j], i + 1, j + 1});
    }
  }

  sort(arr.begin(), arr.end());

  int left = 0, right = arr.size() - 1;
  while (left < right) {
    int s = arr[left][0] + arr[right][0];
    if (s == x && ok(arr[left], arr[right])) {
      cout << arr[left][1] << ' ' << arr[left][2] << ' ';
      cout << arr[right][1] << ' ' << arr[right][2] << '\n';
      return 0;
    }

    if (s < x) {
      ++left;
    } else {
      --right;
    }
  }

  cout << "IMPOSSIBLE";

  return 0;
}
#include <bits/stdc++.h>
#define int long long int
using namespace std;


int32_t main() {
  int n;
  cin >> n;
  vector<array<int, 3>> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0] >> A[i][1];
    A[i][2] = i;
  }
  sort(A.begin(), A.end());
  set<int> rooms;
  for (int i = 1; i <= n; ++i) rooms.insert(i);

  vector<int> ans(n);
  multiset<array<int, 2>> times;

  for (int i = 0; i < n; ++i) {
    while (!times.empty() && (*(times.begin()))[0] < A[i][0]) {
      auto it = times.begin();
      rooms.insert((*times.begin())[1]);
      times.erase(it);
    }
    ans[A[i][2]] = *rooms.begin();
    rooms.erase(rooms.begin());
    times.insert({A[i][1], ans[A[i][2]]});
  }
  cout << *max_element(ans.begin(), ans.end()) << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> &arr) {
  int n = arr.size();
  int mx = *max_element(arr.begin(), arr.end());
  int cnt[mx + 1];
  memset(cnt, 0, sizeof(cnt));

  for (int x : arr)
    cnt[x]++;

  for (int i = 1; i <= mx; ++i) {
    cnt[i] += cnt[i - 1];
  }
  vector<int> copy = arr;
  for (int i = 0; i < n; ++i) {
    arr[cnt[copy[i]] - 1] = copy[i];
    cnt[copy[i]] -= 1;
  }
}

int32_t main() {
  vector<int> arr{5, 4, 3, 2, 1};
  cout << "Input Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  CountingSort(arr);
  cout << "\nOutput Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  return 0;
}
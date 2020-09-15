#include <bits/stdc++.h>
#define int long long int
using namespace std;

int minimumDivisor(vector<int> arr, int threshold) {
  int N = arr.size();
  int low = 1, high = 1e9, ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += ceil(arr[i] / (mid + 0.0));
    }
    if (sum <= threshold) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << minimumDivisor({1, 5, 7}, 8) << '\n';

  return 0;
}
#include <bits/stdc++.h>
#define li long long int
using namespace std;

int GetPivotIdx(vector<int> A) {
  int n = (int)A.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if ((mid + 1) <= high && A[mid] > A[mid + 1])
      return mid;
    if ((mid - 1) >= low && A[mid - 1] > A[mid])
      return mid - 1;

    if (A[low] >= A[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int LocalMinium(vector<int> A, int key) {
  int n = A.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int m = low + (high - low) / 2;
  }
  cout << ans << '\n';
}

int PivotedBinarySearch(vector<int> A, int key) {
  int n = (int)A.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (A[mid] == key)
      return mid;
    if (A[low] <= A[mid]) { // left half is sorted
      if (A[low] <= key && key <= A[mid]) {
        // key lies in the left half
        high = mid - 1;
      } else {
        low = mid + 1;
      }
      continue;
    }

    // Now, if left half is not sorted then right half needs to be sorted
    if (A[mid] <= key && key <= A[high]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int32_t main() {
  int n, key;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  cin >> key;
  cout << PivotedBinarySearch(arr, key) << endl;
  return 0;
}
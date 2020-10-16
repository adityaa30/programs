#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    int k = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > k) {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = k;
  }
}

int32_t main() {
  vector<int> arr{5, 4, 3, 2, 1};
  cout << "Input Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  InsertionSort(arr);
  cout << "\nOutput Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  return 0;
}
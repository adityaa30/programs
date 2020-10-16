#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < (n - i - 1); ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int32_t main() {
  vector<int> arr{5, 4, 3, 2, 1};
  cout << "Input Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  BubbleSort(arr);
  cout << "\nOutput Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  return 0;
}
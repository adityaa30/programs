#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[idx])
        idx = j;
    }
    swap(arr[idx], arr[i]);
  }
}

int32_t main() {
  vector<int> arr{5, 4, 3, 2, 1};
  cout << "Input Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  SelectionSort(arr);
  cout << "\nOutput Array: ";
  for (int x : arr) {
    cout << x << ' ';
  }
  return 0;
}
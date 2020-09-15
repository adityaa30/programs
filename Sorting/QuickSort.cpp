#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) { return a + rand() % (b - a + 1); }

int PartitionQ(vector<int> &arr, int l, int r) {
  // Randomly choose a pivot
  int pivot = random(l, r);
  swap(arr[pivot], arr[r]);
  int i = l - 1;
  for (int j = l; j <= r - 1; ++j)
    if (arr[j] <= arr[r])
      swap(arr[++i], arr[j]);
  swap(arr[++i], arr[r]);
  return i;
}

void QuickSort(vector<int> &arr, int l, int r) {
  if (l < r) {
    int p = PartitionQ(arr, l, r);
    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, r);
  }
}

int main() {
  srand(time(0));
  vector<int> arr = {10, 9, 8, 7, 6, 10, 13};
  int N = arr.size();
  QuickSort(arr, 0, N - 1);
  for (int i = 0; i < N; ++i)
    printf("%d ", arr[i]);
  return 0;
}
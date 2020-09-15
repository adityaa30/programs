#include <bits/stdc++.h>
#define li long long int
using namespace std;

void heapify(li  *arr, li n, li i) {
    li largest = i;
    li l = 2 * i + 1;
    li r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(li *arr, li n) {
    for(li i = n/2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for(li i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    li n;
    cin >> n;
    li arr[n];
    for(li i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for(li i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
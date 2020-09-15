#include <stdio.h>

void Merge(int *arr, int n, int l, int m, int r) {
    int LeftSize = m - l + 1, RightSize = r - m;

    int LeftArr[LeftSize], RightArr[RightSize];
    for(int i = 0; i < LeftSize; ++i) LeftArr[i] = arr[i + l];
    for(int i = 0; i < RightSize; ++i) RightArr[i] = arr[i + m + 1];

    int i = 0, j = 0, k = l;
    while(i < LeftSize && j < RightSize) {
        if(LeftArr[i] > RightArr[j]) arr[k++] = RightArr[j++];
        else arr[k++] = LeftArr[i++];
    }

    while(i < LeftSize) arr[k++] = LeftArr[i++];
    while(j < RightSize) arr[k++] = RightArr[j++];
}

void MergeSort(int *arr, int n, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, n, l, m);
        MergeSort(arr, n, m + 1, r);
        Merge(arr, n, l, m, r);
    }
}

int main() {
    int arr[] = {10, 5, 3, 6, 5}, n = 5;
    MergeSort(arr, n, 0, n - 1);
    for(int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

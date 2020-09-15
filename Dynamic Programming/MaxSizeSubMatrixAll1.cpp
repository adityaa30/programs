#include <iostream>

int Max(int x, int y) {
    return (x > y ? x : y);
}

int Min(int x, int y) {
    return (x > y) ? y : x;
}

int Min(int x, int y, int z) {
    return Min(x, Min(y, z));
}

int MaxSizeSubMatrix(int **arr, int r, int c) {
    int dp[r][c], ans = 0;
    for(int i = 0; i < r; ++i) {
        dp[i][0] = *(*(arr + i) + 0);
        ans = Max(ans, dp[i][0]);
    }
    for(int i = 0; i < c; ++i) {
        dp[0][i] = *(*(arr + 0) + i);
        ans = Max(ans, dp[0][i]);
    }

    for(int i = 1; i < r; ++i) {
        for(int j = 1; j < c; ++j) {
            if(*(*(arr + i) + j)) {
                dp[i][j] = Min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = Max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    int r = 6, c = 5;
    int **matrix = new int*[r];
    for(int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
    }
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++i) {
            scanf("%d", *(matrix + i) + j);
        }
    printf("%d\n", MaxSizeSubMatrix(matrix, r, c));  
    return 0;
}
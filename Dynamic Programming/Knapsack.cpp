#include <iostream>

int Max(int a, int b) {
    return (a > b ? a : b);
}

int Knapsack(int *wt, int *val, int n, int W) {
    int table[n + 1][W + 1] = {0};

    for(int i = 0; i <= n; ++i) {
        for(int w = 0; w <= W; ++w) {
            if(i == 0 || w == 0) table[i][w] = 0;
            else if(wt[i - 1] <= w) {
                table[i][w] = Max(
                    table[i - 1][w],
                    table[i - 1][w - wt[i - 1]] + val[i - 1]
                );
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    return table[n][W];
}

int main() {
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    // printf("%d\n", n);
    printf("%d\n", Knapsack(wt, val, n, W)); 
    return 0;
}
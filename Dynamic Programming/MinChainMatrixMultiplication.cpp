#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void PrintBrackets(vvi &brackets, int i, int j, int n, char &alpha) {
  if (i == j) {
    cout << alpha;
    alpha += 1;
    return;
  }
  cout << "(";
  PrintBrackets(brackets, i, brackets[i][j], n, alpha);
  PrintBrackets(brackets, brackets[i][j] + 1, j, n, alpha);
  cout << ")";
}

int Matrix(vector<int> &p) {
  const int n = p.size();
  vvi dp(n, vi(n, INT_MAX)), bracket(n, vi(n, INT_MAX));

  for (int i = 1; i < n; ++i)
    dp[i][i] = 0;

  for (int L = 2; L < n; ++L) {
    for (int i = 1; i < n - L + 1; ++i) {
      int j = i + L - 1;
      for (int k = i; k < j; ++k) {
        int foo = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (foo < dp[i][j]) {
          dp[i][j] = foo;
          bracket[i][j] = k;
        }
      }
    }
  }
  char start = 'A';
  PrintBrackets(bracket, 1, n - 1, n, start);
  cout << "\n";
  return dp[1][n - 1];
}

int main() {
  vector<int> inp = {1, 2, 3, 4, 3};
  cout << Matrix(inp);
  return 0;
}
#include <bits/stdc++.h>
using li = int64_t;
using namespace std;

// Returns the longest palidromic substring
string LongestPalidromicSubsequence(string str) {
  li n = str.length(), maxLen, startIdx;
  bool dp[n][n] = {false}; // dp[i, j] = True if substring(i, j) is palidrom

  // length = 1
  maxLen = 1;
  startIdx = 0;
  for (li i = 0; i < n; ++i) {
    dp[i][i] = true;
  }

  // length = 2
  for (li i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) {
      dp[i][i + 1] = true;
      maxLen = 2;
      startIdx = i;
    }
  }

  // length > 2
  for (li l = 3; l <= n; ++l) {
    for (li i = 0; (i + l - 1) < n; ++i) {
      li j = i + l - 1;
      if (str[i] == str[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        maxLen = l;
        startIdx = i;
      }
    }
  }

  return str.substr(startIdx, maxLen);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;
  cout << LongestPalidromicSubsequence(str) << '\n';
  return 0;
}
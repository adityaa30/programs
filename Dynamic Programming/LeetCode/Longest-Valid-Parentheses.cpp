// adityaa30
// https://leetcode.com/problems/longest-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    const int N = s.length();
    if (N <= 1) return 0;
    int dp[N];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i < N; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = 2;
          if (i >= 2) dp[i] += dp[i - 2];
        } else if (s[i - 1] == ')' && (i - dp[i - 1]) >= 1 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] + 2;
          if (i - dp[i - 1] >= 2) dp[i] += dp[i - dp[i - 1] - 2];
        }
      }
      ans = max(dp[i], ans);
    }
    return ans;
  }

  int longestValidParanthesisNoSpace(string s) {
    int open = 0, close = 0;
    int ans = 0;
    for (char c : s) {
      
    }

    return ans;
  }
};

int32_t main() {
  Solution s;
  assert(s.longestValidParentheses("(()") == 2);
  assert(s.longestValidParentheses(")()())") == 4);
  assert(s.longestValidParentheses(")()(())") == 6);
  assert(s.longestValidParentheses("") == 0);
  return 0;
}
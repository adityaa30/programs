// adityaa30
// https://leetcode.com/problems/decode-ways-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const long long int MOD = (long long int) (1e9 + 7); 
  int numDecodings(string s) {
    // 0 -> '*', 1-9
    int n = (int) s.length();
    long long int dp[n + 1];
    memset(dp, 0LL, sizeof(dp));
    dp[0] = 1;
    dp[1] = (s[0] == '*' ? 9LL : (s[0] == '0' ? 0LL : 1LL));
    for (int i = 1; i < n; ++i) {
      if (s[i] == '*') {
        dp[i + 1] = 9LL * dp[i];
        if (s[i - 1] == '1') dp[i + 1] += dp[i - 1] * 9LL;
        else if (s[i - 1] == '2') dp[i + 1] += dp[i - 1] * 6LL;
        else if (s[i - 1] == '*') dp[i + 1] += dp[i - 1] * (6LL + 9LL);
      } else { /* s[i] != '*' */
        dp[i + 1] = (s[i] == '0' ? 0LL : dp[i]);
        bool between0to6 = ('0' <= s[i] && s[i] <= '6');
        if (s[i - 1] == '1') dp[i + 1] += dp[i - 1];
        else if (s[i - 1] == '2' && between0to6) dp[i + 1] += dp[i - 1];
        else if (s[i - 1] == '*') dp[i + 1] += dp[i - 1] * (between0to6 ? 2LL : 1LL);
      }
      dp[i + 1] %= MOD;
    }
    return (int) dp[n];
  }
};

int32_t main() {
  Solution s;
  assert(s.numDecodings("*") == 9);
  assert(s.numDecodings("1*") == 18);
  assert(s.numDecodings("1*1*0") == 40);

  return 0;
}
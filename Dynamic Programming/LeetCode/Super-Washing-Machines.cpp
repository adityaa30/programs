// adityaa30
// https://leetcode.com/problems/super-washing-machines/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMinMoves(vector<int> machines) {
    const int n = machines.size();
    int target = 0;
    for (int x : machines)
      target += x;
    if (target % n != 0)
      return -1;
    target /= n;

    int ans = 0;

    // prefix + suffix = 0 (always)
    int prefix = 0, suffix = 0; 
    for (int i = 0; i < n; ++i) {
      // We have `prefix` amount of dresses extra on the left side
      // `prefix` can be postive, negative or zero. 
      prefix += (machines[i] - target);

      // total number of operations required to make a[i] = target 
      int total;

      // If we need to send both from the left and right side 
      // then we cannot have 2 simultaneous out operations
      // else we can have receive-send or recieve-receive
      // from both the sides simultaneously  
      if (prefix >= 0 && suffix >= 0) {
        total = prefix + suffix;
      } else {
        total = max(abs(prefix), abs(suffix));
      }
      ans = max(ans, total);
      suffix = -prefix;
    }
    return ans;
  }
};

int32_t main() {
  Solution s;
  assert(s.findMinMoves({1, 0, 5}) == 3);
  assert(s.findMinMoves({0, 3, 0}) == 2);
  assert(s.findMinMoves({0, 2, 0}) == -1);
  return 0;
}
#include <bits/stdc++.h>
#define int long long int
using namespace std;

string reduceK(string str, int k) {
  stack<pair<char, int>> s;
  for (char c : str) {
    if (s.empty() || s.top().first != c) {
      s.push(make_pair(c, 1));
    } else {
        pair<char, int> top = s.top();
        s.pop();
        top.second += 1;
        s.push(top);
    }

    while (!s.empty() && s.top().second >= k) {
        pair<char, int> top = s.top();
        s.pop();
        if (top.second > k) s.push(make_pair(top.first, top.second - k));
    }
  }
  string ans = "";
  while (!s.empty()) {
      pair<char,int> top = s.top();
      s.pop();
      for (int i = 0; i < top.second; ++i) ans += top.first;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << reduceK("abbcccbd", 3) << '\n';

  return 0;
}
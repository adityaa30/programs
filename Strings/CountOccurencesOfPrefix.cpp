#include "PrefixFunction.hpp"
#include <bits/stdc++.h>
using namespace std;

vector<int> PrefixOccurences(string &s) {
  int n = (int) s.length();
  auto lps = PrefixFunction(s);
  vector<int> count(n + 1);
  // count how many times it occurs in the array lps
  for (int i = 0; i < n; ++i) count[lps[i]]++;

  // we know that the length prefix i appears exactly ans[i] times, 
  // then this number must be added to the number of occurrences 
  // of its longest suffix that is also a prefix
  for (int i = n - 1; i > 0; --i) count[lps[i - 1]] += count[i];
  
  // add 1 to count the original prefixes
  for (int i = 0; i <= n; ++i) count[i]++;

  return count;
}

int32_t main() {
  string str = "aaaa";
  auto count = PrefixOccurences(str);
  for (int i = 0; i < str.length(); ++i) {
    cout << str.substr(0, i + 1) << ' ' << count[i + 1] << '\n';
  }
  return 0;
}
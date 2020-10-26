#include "PrefixFunction.hpp"
#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string pattern, string target) {
  int pLen = (int)pattern.length();
  int tLen = (int)target.length();

  pattern += '#';
  auto lps = PrefixFunction(pattern);

  vector<int> idx; // Store idx of all positions where substring found

  int currLps = 0;
  for (int i = 0; i < tLen; ++i) {
    int j = currLps;
    while (j > 0 && target[i] != pattern[j]) j = lps[j - 1];
    currLps = j + (int)(target[i] == pattern[j]);
    if (currLps == pLen) idx.push_back(i - pLen + 1);
  }
  return idx;
}

int32_t main() {
  string pattern = "aa";
  string target = "aaabcaaac";

  auto idx = KMP(pattern, target);
  cout << "Found pattern at indexs: ";
  for (int x : idx) {
    cout << x << ' ';
    assert(pattern == target.substr(x, (int) pattern.length()));
  }
  cout << '\n';

  return 0;
}
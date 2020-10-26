#include "PrefixFunction.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  string str = "abcdabcd";
  auto lps = PrefixFunction(str);
  for (int i = 0; i < str.length(); ++i) {
    cout << str[i] << ' ' << lps[i] << '\n';
  }
  return 0;
}
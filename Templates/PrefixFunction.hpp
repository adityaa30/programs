#include <bits/stdc++.h>
using namespace std;

vector<int> PrefixFunction(string s) {
  int n = (int)s.length();
  // largest prefix which matches with suffix ending at i
  vector<int> lps(n);
  /*
  Observation 1:
  lps[i] always increases by 1,
  remains the same or decreases by any positive value

  => lps[i + 1] > (lps[i] + 1) 
  => `lps[i] = lps[i + 1] - 1 (removing the last character)
  => `lps[i] now becomes better than lps[i]
  => Contradiction

  => Hence the prefix function can always increase by n for the
  entire string. 
  => Therefore, we just have to perform at max n string operations.

  Observation 2:
  if (s[i + 1] == s[lps[i]]) => lps[i + 1] = lps[i] + 1
  else
  => We need to try a shorter string
  => Let's move immediately to j < lps[i] s.t. s[0 .. j - 1] = s[i - j + 1 .. i]

  */

  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j]) j = lps[j - 1];
    if (s[i] == s[j]) j++;
    lps[i] = j;
  }
  return lps;
}

#include <bits/stdc++.h>
#define fio                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define li long long int
#define MAX_CHAR 256
using namespace std;

string SmallestWindowContainingAllChars(string s1, string s2) {
  if (s2.size() < s1.size())
    return "No window exist";

  li patternCount[MAX_CHAR], origCount[MAX_CHAR];

  for (char x : s2)
    patternCount[x]++;

  li count = 0, start = 0, startIdx = -1, minLength = s2.size();
  for (li i = 0; i < s1.size(); ++i) {
    origCount[s1[i]]++;
    if (patternCount[s1[i]] != 0 && origCount[s1[i]] <= patternCount[s1[i]])
      count++;
    if (count == s2.size()) {
      while (patternCount[s1[start]] == 0 ||
             origCount[s1[start]] > patternCount[s1[start]]) {
        if (origCount[s1[start]] > patternCount[s1[start]])
          origCount[s1[start]]--;
        count++;
      }
      li windowsLength = i - start + 1;
      if (minLength > windowsLength) {
        minLength = windowsLength;
        startIdx = start;
      }
    }
  }
  if (startIdx == -1)
    return "No window exist";
  return s1.substr(startIdx, minLength);
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << SmallestWindowContainingAllChars(s1, s2) << endl;
  return 0;
}
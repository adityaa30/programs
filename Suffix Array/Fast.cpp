#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
  /**
   * Preparations Done:
   * 1. Add $ to the end of input string (smallest ASCII value
   * among all characters of the string)
   * 2. Make the length of all the strings the same by writing all
   * other characters in the string after $ in a cycle.
   * Now, instead of sorting the suffixes - we have to sort the cyclic
   * shifts of the strings.
   * 3. Make the length of the string nearest power of 2 - add more
   * characters in a cycle untill the length of string becomes power of 2
   * 4. Build the table each time increasing the length of string (number
   * of columns = sorted strings) twice. - Dividing the algorithm in LogN
   * iterations.
   */

private:
  int N;
  vector<int> p, c;

  // p: Position of the suffix array
  // c: Equivalence class index (used to compare to 2 strings in O(1) time)

  void CountSort() {
    // Sorts array p by values stored in array c
    vector<int> cnt(N);
    for (int x : this->c) {
      cnt[x]++;
    }
    vector<int> pNew(N), pos(N);
    pos[0] = 0;
    for (int i = 1; i < N; ++i) {
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (int x : p) {
      int bucketIdx = c[x];
      pNew[pos[bucketIdx]] = x;
      pos[bucketIdx]++;
    }
    this->p = pNew;
  }

public:
  string S;

  SuffixArray(string s) {
    this->S = s + '$';
    this->N = this->S.length();
    this->p = vector<int>(this->N);
    this->c = vector<int>(this->N);

    {
      // K = 0
      vector<pair<char, int>> col(N);
      for (int i = 0; i < N; ++i)
        col[i] = {this->S[i], i};
      // Sort this column (at k'th step)
      // O(N * logN)
      sort(col.begin(), col.end());
      for (int i = 0; i < N; ++i) {
        // Update the positions
        p[i] = col[i].second;
      }
      c[p[0]] = 0; // First equivalue class with idx=0
      for (int i = 1; i < N; ++i) {
        // Assign equivalence classes
        c[p[i]] = c[p[i - 1]] + (int)(col[i].first != col[i - 1].first);
      }
    }

    // O(N * logN)
    int k = 0;
    while ((1 << k) < this->N) {
      // Shift all pointers in array p 2^k to left
      for (int i = 0; i < N; ++i) {
        p[i] = (p[i] - (1 << k)) % N;
        p[i] = (p[i] + N) % N;
      }

      // We now have the strings sorted according to right half
      // Use counting sort to sort according to first half as well.

      this->CountSort(); // O(N)
      vector<int> cNew(N);
      cNew[p[0]] = 0;
      for (int i = 1; i < N; ++i) {
        pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]};
        pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % N]};
        cNew[p[i]] = cNew[p[i - 1]] + (int)(now != prev);
      }
      this->c = cNew;

      k += 1;
    }

    // Total Time: O(N * logN) + O(N) = O(N * logN) approx
  }

  int operator[](const int idx) { return this->p[idx]; }
  int length() { return this->N; }

  const int FOUND = 1, SMALL = 2, BIG = 3;
  int ComparePrefix(int sufIdx, string &s) {
    for (int i = 0; i < s.length() && (i + sufIdx) < S.length(); ++i) {
      if (s[i] != this->S[i + sufIdx]) {
        return (s[i] < this->S[i + sufIdx]) ? SMALL : BIG;
      }
    }
    return (s.length() <= (S.length() - sufIdx - 1)) ? FOUND : SMALL;
  }
};

void Solve(int test) {
  string S;
  cin >> S;
  SuffixArray sa(S);
  const int N = sa.length();

  for (int i = 0; i < N; ++i) {
    cout << sa[i] << ' ' << sa.S.substr(sa[i]) << '\n';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve(test);
  }

  return 0;
}
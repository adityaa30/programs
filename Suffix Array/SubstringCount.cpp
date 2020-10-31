#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
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

  int LowerBound(string &s);
  int LastOccurence(string &s);
};

int SuffixArray::LastOccurence(string &s) {
  int low = 0, high = S.length() - 1;
  int idx = S.length();
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int what = ComparePrefix(p[mid], s);
    if (what == FOUND) {
      idx = mid;
      low = mid + 1;
    } else if (what == SMALL) {
      high = mid - 1;
    } else if (what == BIG) {
      low = mid + 1;
    } else {
      assert(false);
    }
  }
  return idx;
}

int SuffixArray::LowerBound(string &s) {
  int low = 0, high = S.length() - 1;
  int idx = S.length();
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int what = ComparePrefix(p[mid], s);
    if (what == FOUND) {
      idx = mid;
      high = mid - 1;
    } else if (what == SMALL) {
      high = mid - 1;
    } else if (what == BIG) {
      low = mid + 1;
    } else {
      assert(false);
    }
  }
  return idx;
}

void Solve(int test) {
  string S;
  cin >> S;
  const int N = S.length();
  SuffixArray sa(S);
  int q;
  cin >> q;
  for (int query = 1; query <= q; ++query) {
    string str;
    cin >> str;
    int first = sa.LowerBound(str);
    if (first == sa.length()) {
      cout << "0\n";
    } else {
      int last = sa.LastOccurence(str);
      cout << (last - first + 1) << '\n';
    }
  }
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
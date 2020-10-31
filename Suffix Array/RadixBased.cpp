#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
  int N;
  string S;
  vector<int> p, c;

  template <class T> void Update(vector<pair<T, int>> &col) {
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

  void RadixSort(vector<pair<array<int, 2>, int>> &);

public:
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
      this->Update(col);
    }

    // O(N * logN)
    int k = 0;
    while ((1 << k) < this->N) {
      vector<pair<array<int, 2>, int>> col(N);
      for (int i = 0; i < N; ++i) {
        col[i] = {{c[i], c[(i + (1 << k)) % N]}, i};
      }
      RadixSort(col);
      this->Update(col);
      k += 1;
    }

    // Total Time: O(N * logN) approx
  }

  int operator[](const int idx) { return this->p[idx]; }
  int length() { return this->N; }
};

void SuffixArray::RadixSort(vector<pair<array<int, 2>, int>> &col) {
  int N = col.size();
  for (int digit = 1; digit >= 0; --digit) {
    vector<int> cnt(N, 0);
    for (auto x : col) {
      cnt[x.first[digit]]++;
    }
    vector<pair<array<int, 2>, int>> colNew(N);
    vector<int> pos(N);
    pos[0] = 0;
    for (int i = 1; i < N; ++i) {
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : col) {
      int idx = x.first[digit];
      colNew[pos[idx]] = x;
      pos[idx]++;
    }
    col = colNew;
  }
}

void Solve(int test) {
  string S;
  cin >> S;
  SuffixArray sa(S);
  const int N = sa.length();

  for (int i = 0; i < N; ++i) {
    cout << sa[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  //   cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve(test);
  }

  return 0;
}
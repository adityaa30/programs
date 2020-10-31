#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
  int N;
  string S;
  vector<int> p, c;

  template <class T> void Update(vector<pair<T, int>> &col) {
    // Sort this column (at k'th step)
    // We use the comparator of T
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
      this->Update(col); // O(N * logN)
    }

    // O(N * (logN)^2)
    int k = 0;
    while ((1 << k) < this->N) {
      vector<pair<pair<int, int>, int>> col(N);
      for (int i = 0; i < N; ++i) {
        col[i] = {{c[i], c[(i + (1 << k)) % N]}, i};
      }
      this->Update(col);
      k += 1;
    }

    // Total Time: O((N * logN) + (N * (logN)^2)) = O(N * (logN)^2) approx
  }

  int operator[](const int idx) { return this->p[idx]; }
  int length() { return this->N; }
};

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
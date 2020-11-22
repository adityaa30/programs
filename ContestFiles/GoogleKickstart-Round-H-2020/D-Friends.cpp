#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int INF = 1e9;
void Solve(int test) {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> mat(26, vector<int>(26, INF));
  vector<string> names(N);
  for (int x = 0; x < N; ++x) {
    string name;
    cin >> name;
    names[x] = name;

    for (char c : name) {
      int idx = c - 'A';
      for (char c2 : name) {
        int i = c2 - 'A';
        if (i == idx)
          continue;
        mat[i][idx] = 1;
        mat[idx][i] = 1;
      }
    }
  }

  for (int i = 0; i < 26; ++i)
    mat[i][i] = 0;

  // Floyd Warshall
  for (int k = 0; k < 26; ++k) {
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  cout << "Case #" << test << ":";
  for (int q = 0; q < Q; ++q) {
    int from, to;
    cin >> from >> to;
    --from, --to;
    int mn = INF;
    for (char c1 : names[from]) {
      for (char c2 : names[to]) {
        mn = min(mn, mat[c1 - 'A'][c2 - 'A']);
      }
    }
    if (mn == INF)
      cout << " -1";
    else
      cout << " " << 2 + mn;
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve(test);
  }

  return 0;
}
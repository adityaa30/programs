#include <bits/stdc++.h>
using namespace std;

const vector<int> dX = {0, 0, 1, -1};
const vector<int> dY = {1, -1, 0, 0};

int32_t main() {
  int r, c;
  cin >> r >> c;

  vector<string> A(r);
  for (int i = 0; i < r; ++i) {
    cin >> A[i];
  }

  auto bfs = [&](int s_x, int s_y) {
    queue<pair<int, int>> q;
    q.push({s_x, s_y});
    A[s_x][s_y] = '?';

    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int x = a + dX[k], y = b + dY[k];
        if (0 <= x && x < r && 0 <= y && y < c && A[x][y] == '.') {
          A[x][y] = '?';
          q.push({x, y});
        }
      }
    }
  };

  int count = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (A[i][j] == '.') {
        ++count;
        bfs(i, j);
      }
    }
  }

  cout << count << '\n';

  return 0;
}

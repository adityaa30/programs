#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const vector<int> dX = {0, 0, 1, -1};
const vector<int> dY = {1, -1, 0, 0};
const vector<char> MOVE = {'R', 'L', 'D', 'U'};

int32_t main() {
  int r, c;
  cin >> r >> c;

  vector<string> M(r);
  pair<int, int> A, B;
  for (int i = 0; i < r; ++i) {
    cin >> M[i];
    for (int j = 0; j < c; ++j) {
      if (M[i][j] == 'A') {
        A = {i, j};
      } else if (M[i][j] == 'B') {
        B = {i, j};
      }
    }
  }

  // (distance, x, y)
  vector<vector<array<int, 3>>> D(r, vector<array<int, 3>>(c, {INF, -1, -1}));

  vector<vector<char>> prev(r, vector<char>(c, 'x'));
  queue<pair<int, int>> q;
  q.push(A);
  D[A.first][A.second][0] = 0;

  while (!q.empty()) {
    auto [a, b] = q.front();
    q.pop();

    if (make_pair(a, b) == B) {
      break;
    }

    for (int k = 0; k < 4; ++k) {
      int x = a + dX[k], y = b + dY[k];
      if (0 <= x && x < r && 0 <= y && y < c && (M[x][y] == '.' || M[x][y] == 'B')) {
        M[x][y] = '?';
        q.push({x, y});

        if (D[x][y][0] >= (D[a][b][0] + 1)) {
          D[x][y] = {D[a][b][0] + 1, a, b};
          prev[x][y] = MOVE[k];
        }
      }
    }
  }

  if (D[B.first][B.second][0] == INF) {
    cout << "NO\n";
    return 0;
  }

  string moves = "";
  pair<int, int> curr = B;
  while (curr != A) {
    moves += prev[curr.first][curr.second];
    auto d = D[curr.first][curr.second];
    curr = make_pair(d[1], d[2]);
  }

  reverse(moves.begin(), moves.end());

  cout << "YES\n";
  cout << D[B.first][B.second][0] << '\n';
  cout << moves << '\n';

  return 0;
}

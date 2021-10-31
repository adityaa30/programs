#include <bits/stdc++.h>
using namespace std;

const vector<int> dX = {0, 0, 1, -1};
const vector<int> dY = {1, -1, 0, 0};
const vector<char> MOVE = {'R', 'L', 'D', 'U'};

int32_t main() {
  int r, c;
  cin >> r >> c;

  vector<queue<pair<int, int>>> queues; // (last - me, other - monster)

  pair<int, int> A;

  vector<string> grid(r);
  for (int i = 0; i < r; ++i) {
    cin >> grid[i];
  }

  auto ok_to_create = [&](int a, int b) {
    for (int k = 0; k < 4; ++k) {
      int x = a + dX[k], y = b + dY[k];
      if (0 <= x && x < r && 0 <= y && y < c && grid[x][y] == '.') {
        return true;
      }
    }
    return false;
  };

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (grid[i][j] == 'M') {
        if (ok_to_create(i, j)) {
          queues.push_back(queue<pair<int, int>>());
          queues.back().push({i, j});
        }
      } else if (grid[i][j] == 'A') {
        A = {i, j};
      }
    }
  }

  queues.push_back(queue<pair<int, int>>());
  queues.back().push(A);

  vector<vector<char>> prev_dir(r, vector<char>(c, '-'));
  vector<vector<pair<int, int>>> prev(r, vector<pair<int, int>>(c, {-1, -1}));
  pair<int, int> quit = {-1, -1};

  auto step = [&](queue<pair<int, int>> &q, bool me) {
    int sz = q.size();
    for (int i = 0; i < sz; ++i) {
      auto [a, b] = q.front();
      q.pop();

      if (me && (a == 0 || b == 0 || a == (r - 1) || b == (c - 1))) {
        quit = {a, b};
        return;
      }

      for (int k = 0; k < 4; ++k) {
        int x = a + dX[k], y = b + dY[k];
        if (0 <= x && x < r && 0 <= y && y < c && grid[x][y] == '.') {
          grid[x][y] = (me ? '$' : '?');
          q.push({x, y});

          if (me) {
            prev[x][y] = {a, b};
            prev_dir[x][y] = MOVE[k];
          }
        }
      }
    }
  };

  bool done = false;
  while (!done && quit.first == -1) {

    done = true;
    for (int idx = 0; idx < queues.size(); ++idx) {
      step(queues[idx], (idx + 1) == queues.size());
      done = done && queues[idx].empty();
    }
  }

  if (quit.first == -1) {
    cout << "NO\n";
    return 0;
  }

  string moves = "";
  auto last = quit;
  while (last != A) {
    moves += prev_dir[last.first][last.second];
    last = prev[last.first][last.second];
  }
  reverse(moves.begin(), moves.end());

  cout << "YES\n";
  cout << moves.size() << '\n';
  cout << moves << '\n';

  return 0;
}

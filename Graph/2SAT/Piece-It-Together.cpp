// Problem - https://open.kattis.com/problems/pieceittogether
// Solution - https://www.youtube.com/watch?v=0nNYy3rltgA
#include <TwoSAT.hpp>
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

// U, L, D, R
const vi dx = {-1, 0, 1, 0};
const vi dy = {0, -1, 0, 1};

const int NO_EDGE = -1;

int32_t main() {
  int h, w;
  cin >> h >> w;

  auto in_bounds = [&](int r, int c) {
    return (0 <= r && r < h && 0 <= c && c < w);
  };

  vector<string> grid(h);
  for (int i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  viii ids(4, vii(h, vi(w, NO_EDGE)));
  int num_terms = 0, num_white = 0, num_black = 0;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      num_white += (int)(grid[i][j] == 'W');
      num_black += (int)(grid[i][j] == 'B');
      int black_neigbours = 0;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (in_bounds(x, y)) {
          if (grid[i][j] == 'B' && grid[x][y] == 'W') {
            ids[k][i][j] = num_terms++;
          }
          if (grid[x][y] == 'B') {
            ++black_neigbours;
          }
        }
      }

      if (grid[i][j] == 'W' && black_neigbours == 0) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  if (num_white != 2 * num_black) {
    cout << "NO\n";
    return 0;
  }

  TwoSAT helper(num_terms);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int k = 0; k < 2; ++k) {
        int id1 = ids[k][i][j];
        int id2 = ids[k + 2][i][j];
        if (id1 != NO_EDGE && id2 != NO_EDGE) {
          helper.add_xor(id1, id2);
        } else if (id1 != NO_EDGE) {
          helper.force_var(id1);
        } else if (id2 != NO_EDGE) {
          helper.force_var(id2);
        }
      }

      if (grid[i][j] == 'B') {
        for (int k = 0; k < 2; ++k) {
          if (ids[k][i][j] == NO_EDGE && ids[k + 2][i][j] == NO_EDGE) {
            cout << "NO\n";
            return 0;
          }
        }
      }

      if (grid[i][j] == 'W') {
        vector<int> neighbours;
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k], y = j + dy[k];
          if (in_bounds(x, y) && grid[x][y] == 'B') {
            neighbours.push_back(ids[(k + 2) % 4][x][y]);
          }
        }

        for (size_t a = 0; a < neighbours.size(); ++a) {
          for (size_t b = a + 1; b < neighbours.size(); ++b) {
            // Both neighbours should not be chosen together
            // ~(1 & 2) => (~1 | ~2)
            int id1 = helper.negate(neighbours[a]);
            int id2 = helper.negate(neighbours[b]);
            helper.add_or(id1, id2);
          }
        }
      }
    }
  }

  cout << (helper.run() ? "YES\n" : "NO\n");
  return 0;
}
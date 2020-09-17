// adityaa30
// Problem Link - https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int EMPTY = 0;
const int FRESH = 1;
const int ROTTEN = 2;

const int PosX[4] = {0, 1, 0, -1};
const int PosY[4] = {1, 0, -1, 0};

class Solution {
public:
  int orangesRotting(vector<vector<int>> grid) {
    int N = grid.size(), M = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == ROTTEN) {
          q.push({i, j});
        }
      }
    }
    int ans = 0;
    while (!q.empty()) {
      ++ans;
      int sz = q.size();
      while (sz--) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int newX = PosX[k] + curr.x, newY = PosY[k] + curr.y;
          if (0 <= newX && newX < N && 0 <= newY && newY < M &&
              grid[newX][newY] == FRESH) {
            grid[newX][newY] = ROTTEN;
            q.push({newX, newY});
          }
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == FRESH) {
          return -1;
        }
      }
    }
    return max(0, ans - 1);
  }
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution s;
  cout << s.orangesRotting({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) << '\n';
  cout << s.orangesRotting({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}) << '\n';
  cout << s.orangesRotting({{0, 2}}) << '\n';
}
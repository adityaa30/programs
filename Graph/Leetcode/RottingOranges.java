// adityaa30
// Problem Link - https://leetcode.com/problems/rotting-oranges/
import java.util.LinkedList;
import java.util.Queue;

class Point {
  int x, y;

  Point(int x, int y) {
    this.x = x;
    this.y = y;
  }
}

class Solution {
  public final static int EMPTY = 0;
  public final static int FRESH = 1;
  public final static int ROTTEN = 2;

  public final static int[] PosX = {0, 1, 0, -1};
  public final static int[] PosY = {1, 0, -1, 0};

  public static int orangesRotting(int[][] grid) {
    int N = grid.length, M = grid[0].length;
    Queue<Point> q = new LinkedList<>();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == ROTTEN) {
          q.add(new Point(i, j));
        }
      }
    }

    int steps = 0;
    while (!q.isEmpty()) {
      steps += 1;
      int sz = q.size();
      while (sz-- > 0) {
        Point curr = q.remove();
        for (int k = 0; k < 4; ++k) {
          int newX = PosX[k] + curr.x, newY = PosY[k] + curr.y;
          if (0 <= newX && newX < N && 0 <= newY && newY < M &&
              grid[newX][newY] == FRESH) {
            grid[newX][newY] = ROTTEN;
            q.add(new Point(newX, newY));
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
    return Math.max(0, steps - 1);
  }

  public final static void main(String[] args) {
    int[][] grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int[][] grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    int[][] grid3 = {{0, 2}};
    System.out.println(Solution.orangesRotting(grid1)); // 4
    System.out.println(Solution.orangesRotting(grid2)); // -1
    System.out.println(Solution.orangesRotting(grid3)); // 0
  }
}
// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
#define print(it)                                                              \
  cout << #it << ' -> ';                                                       \
  for (auto __x__ : it)                                                        \
    cout << __x__ << ' ';                                                      \
  cout << '\n';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1, 1, 1, -1, -1};
int PosY[] = {1, 0, -1, 0, 1, -1, 1, -1};

// pair(Weight, Idx)

struct Pair {
  int weight, idx;

  Pair(int weight, int idx) : weight(weight), idx(idx) {}
};

void FloydWarshall(vector<vector<int>> &graph) {
  int V = graph.size();
  vector<vector<int>> dp = graph;
  for (int k = 0; k < V; ++k) {
    for (int u = 0; u < V; ++u) {
      for (int v = 0; v < V; ++v) {
        dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
      }
    }
  }

  for (vector<int> row : dp) {
    for (int elem : row) {
      if (elem == INT_MAX)
        cout << "INF\t";
      else
        cout << elem << '\t';
    }
    cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  vector<vector<int>> graph = {{0, 5, INT_MAX, 10},
                               {INT_MAX, 0, 3, INT_MAX},
                               {INT_MAX, INT_MAX, 0, 1},
                               {INT_MAX, INT_MAX, INT_MAX, 0}};

  FloydWarshall(graph);

  return 0;
}
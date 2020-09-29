// https://github.com/adityaa30/cp-cli
// https://www.codechef.com/LTIME88A/problems/PERMSPL
#include <bits/stdc++.h>
#define var(x) #x, x
#define int long long int
using namespace std;

void Solve(int test) {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; ++i)
    cin >> P[i];

  /**
   * Create a graph where each edge is inversion count
   * Split set of vertices V into V1 and V2 such that number
   * of internal edges are equal
   * Cross Edge - Edge AB where A is in V1 and B is in V2
   * Observation 1:
   *  Every cross edge appears once in V1 and V2
   *  i.e Cross Edge is counted once in V1 and V2 (total twice)
   *
   * Observation 2:
   *  #(edges in V1) == #(edges in V2)     [Multiply by constant 2]
   *  #(2 * edges in V1) == #(2 * edges in V2)
   *
   * Using Observation 1 & 2, for each set:
   *  - Include Cross Edges once (Obs 1)
   *  - Include Internal Edges twice (Obs 2)
   *
   * Hence it is enough to check:
   *  SumDegree(V1) = SumDegree(V2)
   *  SumDegree(V1) = (1/2) SumDegree(V)
   *  SumDegree(V1) = SumDegree(V2) = |E| [No. of edges in V]
   *  - Subset Sum DP :)
   */

  vector<int> deg(N + 1, 0);
  int edges = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (P[i] > P[j]) {
        deg[i + 1]++, deg[j + 1]++;
        edges += 1;
      }
    }
  }

  /*
  vector<vector<int>> dp(N + 1, vector<int>(edges + 1, -1));
  function<int(int, int)> check = [&](int pos, int sum) {
    if (dp[pos][sum] != -1) return dp[pos][sum];
    if (sum == 0) return dp[pos][sum] = 1LL;
    if (pos == 0) return dp[pos][sum] = 0LL;

    int ans = check(pos - 1, sum); // not take
    if (sum - deg[pos] >= 0) ans = ans || check(pos - 1, sum - deg[pos]); //
  take return dp[pos][sum] = ans;
  };

  check(N, edges);
  if (dp[N][edges] == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  // Max number of edges = (N(N + 1))/2
  // Total Space = O(N^3)
  // Total Time = O(N^3)
  */

  bitset<10005> dp;
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    dp = dp | (dp << deg[i]);
  }

  cout << (dp[edges] == 1 ? "YES\n" : "NO\n");
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve(test);
  }

  return 0;
}
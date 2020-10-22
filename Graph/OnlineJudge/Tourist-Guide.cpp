// adityaa30
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1140
#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -1;

void Solve(int mapIdx, int N) {
  map<string, int> city2idx;
  vector<string> cities(N);

  for (int idx = 0; idx < N; ++idx) cin >> cities[idx];
  sort(cities.begin(), cities.end());
  for (int idx = 0; idx < N; ++idx) {
    city2idx[cities[idx]] = idx;
  }

  int R;
  cin >> R;
  vector<vector<int>> adj(N);
  for (int i = 0; i < R; ++i) {
    string fromCity, toCity;
    cin >> fromCity >> toCity;
    int fromIdx = city2idx[fromCity], toIdx = city2idx[toCity];
    adj[fromIdx].push_back(toIdx);
    adj[toIdx].push_back(fromIdx);
  }

  vector<int> entryTime(N, -1), lowestTime(N, -1);
  vector<bool> visited(N, false);
  int timer = 0;
  
  set<int> cameraIdx;
  
  function<void(int, int)> dfs = [&](int curr, int parent) {
    visited[curr] = true;
    entryTime[curr] = lowestTime[curr] = timer++;
    int childrenCount = 0;    
    for (int child : adj[curr]) {
      if (child == parent) continue;
      else if (visited[child]) lowestTime[curr] = min({lowestTime[curr], entryTime[child]});
      else {
        dfs(child, curr);
        lowestTime[curr] = min(lowestTime[curr], lowestTime[child]);
        if (lowestTime[child] >= entryTime[curr] && parent != NO_PARENT) {
          cameraIdx.insert(curr);
        }
        childrenCount++;
      }
    }
    if (childrenCount > 1 && parent == NO_PARENT) {
      cameraIdx.insert(curr);
    }
  };

  for (int i = 0; i < N; ++i) if (!visited[i]) dfs(i, NO_PARENT);

  cout << "City map #" << mapIdx << ": " << cameraIdx.size() << " camera(s) found\n";
  for (int idx : cameraIdx) {
    cout << cities[idx] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int mapIdx = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    if (mapIdx > 1) cout << '\n';
    Solve(mapIdx++, n);
  }
  return 0;
}
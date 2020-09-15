/** Based on Dijkstra Algorithm - Print all paths
 * https://leetcode.com/problems/alphabet-board-path/submissions/
 */

#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};

vector<vector<pair<char, char>>> graph(26);

using iPair = pair<int, int>;
using MinHeap = priority_queue<iPair, vector<iPair>, greater<iPair>>;

int C[] = {'U', 'R', 'D', 'L'};
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};

void generateGraph() {
  auto check = [](int _x, int _y) {
    return (0 <= _x && _x < 5) && (0 <= _y && _y < 5);
  };

  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      for (int k = 0; k < 4; ++k) {
        int newX = X[k] + i, newY = Y[k] + j;
        if (check(newX, newY)) {
          graph[board[i][j] - 'a'].push_back({board[newX][newY], C[k]});
        }
      }

  // Add z
  graph['z' - 'a'].push_back({'u', 'U'});
  graph['u' - 'a'].push_back({'z', 'D'});
}

string key(char x, char y) {
  string k = "";
  k += x;
  k += y;
  return k;
}

void getPath(vector<pair<int, char>> &parent, int dest, string &path) {
  if (parent[dest].first == -1)
    return;
  getPath(parent, parent[dest].first, path);
  path += parent[dest].second;
}

void AddPaths(vector<vector<string>> &paths, int start) {
  // adds all paths available from start
  MinHeap pq;
  vector<int> distance(26, INT_MAX);
  vector<pair<int, char>> parent(26, {-1, 'x'});

  pq.push({0, start}); // (distance, vertex)
  distance[start] = 0;

  while (!pq.empty()) {
    int vertex = pq.top().second;
    pq.pop();

    for (auto child : graph[vertex]) {
      if (distance[child.first - 'a'] > (distance[vertex] + 1)) {
        distance[child.first - 'a'] = distance[vertex] + 1;

        pq.push({distance[child.first - 'a'], child.first - 'a'});
        parent[child.first - 'a'] = {vertex, child.second};
      }
    }
  }

  for (int i = 0; i < 26; ++i) {
    string path = "";
    getPath(parent, i, path);
    paths[start][i] = path;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<string>> paths(26, vector<string>(26, ""));
  generateGraph();
  for (int i = 0; i < 26; ++i)
    AddPaths(paths, i);

  int test = 1;
  cin >> test;
  for (int t = 0; t < test; ++t) {
    string target, ans = "";
    cin >> target;

    if (target[0] != 'a')
      target = 'a' + target;
    else
      ans = "!";

    for (int i = 0; (i + 1) < target.length(); ++i) {
      ans += paths[target[i] - 'a'][target[i + 1] - 'a'] + "!";
    }

    cout << ans << '\n';
  }

  return 0;
}
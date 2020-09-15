// adityaa30
#include <bits/stdc++.h>
#define int long long int
using namespace std;

template <typename A, typename B> string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return to_string(string(1, c)); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void print() { cout << endl; }

template <typename Head, typename... Tail> void print(Head H, Tail... T) {
  cout << " " << to_string(H);
  print(T...);
}

const int MOD = 1e7 + 5;
const int INF = 1e9 + 5;

struct Pair {
  int weight, idx;

  Pair(int weight, int idx) : weight(weight), idx(idx) {}
};

struct ComparePair {
  bool operator()(Pair &a, Pair &b) { return a.weight < b.weight; }
};

void Dijkstra(vector<vector<Pair>> &adj, int src = 0) {
  int V = adj.size();
  vector<int> distance(V, INT_MAX);
  priority_queue<Pair, vector<Pair>, ComparePair> pq;

  distance[src] = 0;
  pq.push(Pair(0, src));

  while (!pq.empty()) {
    Pair top = pq.top();
    pq.pop();
    for (Pair child : adj[top.idx]) {
      if (distance[top.idx] + child.weight < distance[child.idx]) {
        distance[child.idx] = distance[top.idx] + child.weight;
        pq.push(Pair(distance[child.idx], child.idx));
      }
    }
  }

  for (int i = 0; i < distance.size(); ++i) {
    cout << "Distance(" << i << ") = " << distance[i] << '\n';
  }
}

void DijkstraN2(vector<vector<Pair>> &adj, int src = 0) {
  int N = adj.size();
  vector<int> distance(N + 1, INF);
  vector<bool> visited(N + 1, false);
  vector<int> parent(N + 1, -1);

  distance[src] = 0;

  function<int(void)> getMin = [&]() {
    int idx = -1;
    for (int j = 0; j < N; ++j) {
      if (!visited[j] && (idx == -1 || distance[j] < distance[idx])) {
        idx = j;
      }
    }
    return idx;
  };

  /// src --> vertex -> child == (distance[vertex] + weight(vertex-->child))

  // O(N) * O(N + ...) == O(N^2)
  // while (no node is left)
  for (int i = 0; i < N - 1; ++i) {
    // Pick the unvisted vertex with the minimum distance
    int idx = getMin();
    visited[idx] = true;

    // Update all the child
    for (Pair child : adj[idx]) {
      bool ok = (distance[idx] + child.weight < distance[child.idx]);
      if (!visited[child.idx] && ok) {
        parent[child.idx] = idx;
        distance[child.idx] = distance[idx] + child.weight;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << "Distance(" << i << ") = " << distance[i] << " Parent(" << parent[i]
         << ")\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int V = 9;
  vector<vector<Pair>> adj(V);

  function<void(int, int, int)> addEdge = [&](int a, int b, int weight) {
    adj[a].push_back(Pair(weight, b));
    adj[b].push_back(Pair(weight, a));
  };

  addEdge(0, 1, 4);
  addEdge(0, 7, 8);
  addEdge(1, 2, 8);
  addEdge(1, 7, 11);
  addEdge(2, 3, 7);
  addEdge(2, 8, 2);
  addEdge(2, 5, 4);
  addEdge(3, 4, 9);
  addEdge(3, 5, 14);
  addEdge(4, 5, 10);
  addEdge(5, 6, 2);
  addEdge(6, 7, 1);
  addEdge(6, 8, 6);
  addEdge(7, 8, 7);

  //   cout << "Using STL O(NLogE):\n";
  //   Dijkstra(adj);

  cout << "Without STL O(N*N):\n";
  DijkstraN2(adj);

  return 0;
}
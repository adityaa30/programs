/* Google Kickstart 2020 - Problem: BUNDLING */

// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

class Trie {
private:
  struct Node {
    char value;
    map<char, Node *> Children;

    // Number of time the node ends
    // Helps in counting repeated words
    int EndCount = 0;

    Node(char val) : value(val) {}
  };

  Node *root;

  void _PrintAll(Node *current, string s) {
    for (int i = 0; i < current->EndCount; ++i)
      cout << s << endl;

    for (auto x : current->Children)
      _PrintAll(x.second, s + x.first);
  }

public:
  Trie() { root = new Node('#'); }

  Trie::Node &getRoot() { return *(this->root); }

  void Add(string s) {
    Node *current = root;

    for (auto x : s) {
      auto child = current->Children.find(x);
      if (child == current->Children.end()) {
        current->Children[x] = new Node(x);
      }
      current = current->Children[x];
    }
    current->EndCount++;
  }

  int Count(string s) {
    Node *current = root;

    for (auto x : s) {
      auto child = current->Children.find(x);
      if (child == current->Children.end()) {
        return false;
      }
      current = current->Children[x];
    }
    return current->EndCount;
  }

  void PrintAll() { _PrintAll(root, ""); }

  // Helper function -- strategies related to dfs
  int Dfs(Trie::Node &current, int depth, int &ans, int K);
};

int Trie::Dfs(Trie::Node &current, int depth, int &ans, int K) {
  int available = current.EndCount;
  for (auto child : current.Children) {
    available += Dfs(*(child.second), depth + 1, ans, K);
  }

  ans += (available / K) * depth;

  return available % K;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    int N, K;
    string s;
    cin >> N >> K;
    Trie trie;
    for (int i = 0; i < N; ++i) {
      cin >> s;
      trie.Add(s);
    }

    int ans = 0;
    trie.Dfs(trie.getRoot(), 0, ans, K);
    cout << "Case #" << test << ": " << ans << '\n';
  }

  return 0;
}
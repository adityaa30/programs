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
  void Dfs(Trie::Node &current, int depth);
};

int32_t main() { return 0; }
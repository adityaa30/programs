// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
#define print(it)                                                              \
  for (auto __x__ : it)                                                        \
    cout << __x__ << ' ';                                                      \
  cout << '\n';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};


Node *Reverse(Node *root) {
  Node *prev = NULL;
  while (root != NULL) {
    Node *next = root->next;

    // NULL <- 1 .. 2' -> 3
    root->next = prev;
    // NULL <- 1 <- 2' .. 3
    prev = root;

    root = next;
  }
  return prev;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  Node *root = new Node(1);
  root->next = new Node(2);
  root->next->next = new Node(3);
  root->next->next->next = new Node(4);
  root->next->next->next->next = new Node(5);

  PrintList(root);
  root = Reverse(root);
  PrintList(root);

  return 0;
}
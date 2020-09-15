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

struct Node {
    int data;
    Node *left, *right;
};


Node *DLL2BST(Node *curr) {

    // (left) (curr) (right)
    Node *leftTree = DLL2BST(curr->left);
    Node *root = curr;
    root->left = leftTree;
    root->right = curr->next;

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
  }

  return 0;
}
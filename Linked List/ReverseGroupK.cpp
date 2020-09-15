// adityaa30
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

struct Node {
  int data;
  Node *next, *random;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->random = NULL;
  }
};

Node *reverseK(Node *root, int k) {
  // (1, 2, 3, 4, 5, 6, 7)
  // (3, 2, 1, 6, 5, 4, 7)
  Node *prev = NULL, *head = NULL, *next = NULL;
  for (int i = 0; i < k && root != NULL; ++k) {
    next = root->next;
    root->next = prev;

    if (prev == NULL)
      head = root;

    prev = next;
  }

  if (next != NULL) head->next = reverseK(next, k);
  return prev;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  return 0;
}
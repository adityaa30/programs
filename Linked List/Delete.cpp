// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

void Delete(Node **root) {
  Node *curr = *root;
  while (curr != NULL) {
    Node *backup = curr->next;
    free(curr);
    curr = backup;
  }
  *root = NULL;
}

int32_t main() {
  SLL sl({1, 2, 3, 4});
  cout << sl << '\n';
  Delete(&sl.head->next->next);
  cout << sl << '\n';
  return 0;
}
// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

// 1 -> 2 -> 3 -> 4
// 3    2    1    4
// --------->
//      -
// <---------
//                -

// 1 -> 2
// 1 -> 1' -> 2

// 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4'
// 3    X     2    X     1    X     4   X
// 3    3'    2    2'    1    1'   4   4'
// (non-dashed)->next->random = (non-dashed)->random->next
// (1)->random(=3)->next(3')

// 1 -> 2 -> 3 -> 4
// 3    2    1    4

// Time O(N) and Space O(1)

Node *clone(Node *root) {
  Node *curr = root;
  while (curr != NULL) {
    Node *newNode = new Node(curr->data); // dashed
    newNode->next = curr->next;
    curr->next = newNode;
    curr = curr->next->next;
  }

  cout << "Original (during clone): ";
  PrintListRandom(root);

  curr = root;
  while (curr != NULL) {
    curr->next->random = curr->random->next;
    curr = curr->next->next;
  }

  cout << "Original (during clone): ";
  PrintListRandom(root);

  Node *clonedHead = NULL, *clonedCurr = NULL;

  curr = root;
  while (curr != NULL) {
    if (clonedCurr == NULL) {
      clonedHead = curr->next;
      clonedCurr = curr->next;
    } else {
      clonedCurr->next = curr->next;
      clonedCurr = clonedCurr->next;
    }
    curr->next = curr->next->next;
    curr = curr->next;
  }

  return clonedHead;
}

int32_t main() {
  Node *root = new Node(1);
  root->next = new Node(2);
  root->next->next = new Node(3);
  root->next->next->next = new Node(4);

  root->random = root->next->next;             // 1 -> 3
  root->next->random = root->next->next->next; // 2 -> 4
  root->next->next->random = root;             // 3 -> 1
  root->next->next->next->random = root->next->next->next; // 4 -> 4

  cout << "Original (before clone): ";
  PrintListRandom(root);

  Node *clonedHead = clone(root);

  cout << "Original (after clone): ";
  PrintListRandom(root);
  cout << "Clone (after clone): ";
  PrintListRandom(clonedHead);

  return 0;
}
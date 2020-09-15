// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

/**
 * Returns the node inside the cycle
 * If no cycle then returns NULL
 */
Node *GetCycleNode(Node *root) {
  Node *once = root;
  Node *twice = root;

  do {
    twice = twice->next;
    if (twice == NULL) {
      break;
    } else {
      once = once->next;
      twice = twice->next;
    }
  } while (twice != NULL && once != twice);

  return twice;
}

void removeCycle(Node *root) {
  Node *cycleNode = GetCycleNode(root);
  if (cycleNode == NULL)
    return;

  int cycleSize = 0;
  Node *cycleIter = cycleNode;
  do {
    ++cycleSize;
    cycleIter = cycleIter->next;
  } while (cycleIter != cycleNode);

  Node *closeNode = root;
  Node *farNode = root;
  while (cycleSize > 0) {
    --cycleSize;
    farNode = farNode->next;
  }

  while (closeNode != farNode) {
    closeNode = closeNode->next;
    farNode = farNode->next;
  }

  // Iterate to find previous node
  // Worst Case: 1st node is the starting node of cycle
  // We start from the node where the cycle starts here.
  while (closeNode->next != farNode) {
    closeNode = closeNode->next;
  }

  closeNode->next = NULL;
}

int32_t main() {
  SLL sl({1, 2, 3, 4, 5});

  // Make the cycle
  // 1 -> 2 -> 3 -> 4 -> 5
  //      |              |
  //      ----------------

  sl.last->next = sl.head->next;
  removeCycle(sl.head);

  // If we print then ok else we'll endup in infinite loop
  cout << sl << '\n';
  return 0;
}
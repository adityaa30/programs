// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
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

Node *getMiddle(Node *root) {
  Node *jumpOne = root;
  Node *jumpTwo = root;

  // 1 2
  while (jumpTwo != NULL) {
    jumpTwo = jumpTwo->next;

    if (jumpTwo == NULL) {
      // SLL have odd length
      return jumpOne;
    }

    jumpTwo = jumpTwo->next;
    if (jumpTwo == NULL) {
      return jumpOne->next;
    }

    jumpOne = jumpOne->next;
  }
  return jumpOne;
}

bool Compare(Node *first, Node *second) {
  // We assume that both first & second have the exact same length
  while (first != NULL && second != NULL) {
    if (first->data != second->data)
      return false;
    else {
      first = first->next;
      second = second->next;
    }
  }

  return true;
}

bool IsPalidrome(Node *root) {
  Node *middle = getMiddle(root);
  Node *reversedHead = Reverse(middle);
  bool result = Compare(root, reversedHead);

  // Reverse the other half again to make sure that
  // original linked list do not change at the end
  Reverse(reversedHead);

  return result;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  SLL sll1({1, 2, 3, 2, 1});
  SLL sll2({1, 2, 3, 3, 2, 1});
  SLL sll3({1, 2, 3, 4, 5, 6});
  SLL sll4({1, 2, 3, 4, 5, 6, 7});

  cout << sll1 << ' ' << (IsPalidrome(sll1.head) ? "" : "Not") << " Palindrome\n";
  cout << sll2 << ' ' << (IsPalidrome(sll2.head) ? "" : "Not") << " Palindrome\n";
  cout << sll3 << ' ' << (IsPalidrome(sll3.head) ? "" : "Not") << " Palindrome\n";
  cout << sll4 << ' ' << (IsPalidrome(sll4.head) ? "" : "Not") << " Palindrome\n";

  return 0;
}
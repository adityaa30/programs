// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

int Length(Node *root) {
  int l = 0;

  while (root != NULL) {
    ++l;
    root = root->next;
  }

  return l;
}

Node *FindIntersectionPoint(Node *first, Node *second) {
  int firstLen = Length(first), secondLen = Length(second);

  if (firstLen > secondLen) {
    swap(first, second);
    swap(firstLen, secondLen);
  }

  int diff = secondLen - firstLen;

  while (diff > 0) {
    second = second->next;
  }

  while (first != second) {
    first = first->next;
    second = second->next;
  }

  return first;
}

int32_t main() {

  SLL sl1({1, 2, 3});
  SLL sl2({10, 20, 30});
  SLL sl3({4, 5, 6});

  sl1.Add(sl3);
  sl2.Add(sl3);

  cout << sl1 << "\n"; // 1 2 3 4 5 6
  cout << sl2 << "\n"; // 10 20 30 4 5 6

  PrintList(FindIntersectionPoint(sl1.head, sl2.head)); // 4 5 6

  return 0;
}
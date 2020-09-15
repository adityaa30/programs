// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

SLL IntersectionSorted(Node *first, Node *second) {
  SLL sl;

  while (first != NULL && second != NULL) {
    if (first->data < second->data) {
      first = first->next;
    } else if (first->data > second->data) {
      second = second->next;
    } else {
      sl.Add(first->data);
      first = first->next;
      second = second->next;
    }
  }

  return sl;
}

SLL UnionSorted(Node *first, Node *second) {
  SLL sl;

  while (first != NULL && second != NULL) {
    if (first->data < second->data) {
      sl.Add(first->data);
      first = first->next;
    } else if (first->data > second->data) {
      sl.Add(second->data);
      second = second->next;
    } else {
      sl.Add(first->data);
      first = first->next;
      second = second->next;
    }
  }

  while (first != NULL) {
    sl.Add(first->data);
    first = first->next;
  }

  while (second != NULL) {
    sl.Add(second->data);
    second = second->next;
  }

  return sl;
}

int32_t main() {
  SLL sl1({1, 2, 3, 4, 5});
  SLL sl2({1, 3, 5, 7, 9});

  cout << UnionSorted(sl1.head, sl2.head) << '\n';
  cout << IntersectionSorted(sl1.head, sl2.head) << '\n';

  return 0;
}
// adityaa30
#include "Node.hpp"
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

pair<Node *, Node *> SplitHalf(Node *root) {
  if (root == NULL)
    return {NULL, NULL};

  Node *first = root, *second = NULL;
  Node *once = root, *twice = root, *prev = NULL;

  while (twice != NULL) {
    twice = twice->next;
    if (twice == NULL) {
      break;
    } else {
      prev = once;
      once = once->next;
      twice = twice->next;
    }
  }

  prev->next = NULL;
  second = once;

  return {first, second};
}

Node *Merge(Node *first, Node *second) {
  Node *newRoot = NULL, *curr = NULL;

  function<void(Node *)> Add = [&](Node *val) {
    if (newRoot == NULL) {
      newRoot = val;
      curr = val;
    } else {
      curr->next = val;
      curr = curr->next;
    }
  };

  while (first != NULL && second != NULL) {
    if (first->data < second->data) {
      Add(first);
      first = first->next;
    } else if (first->data > second->data) {
      Add(second);
      second = second->next;
    } else {
      Add(first);
      Add(second);
      first = first->next;
      second = second->next;
    }
  }

  while (first != NULL) {
    Add(first);
    first = first->next;
  }

  while (second != NULL) {
    Add(second);
    second = second->next;
  }

  return newRoot;
}

void MergeSort(Node **root) {
  if (*root == NULL || (*root)->next == NULL) {
    return;
  }

  pair<Node *, Node *> split = SplitHalf(*root);
  MergeSort(&split.first);
  MergeSort(&split.second);
  *root = Merge(split.first, split.second);
}

int32_t main() {
  SLL sl({4, 5, 10, 2, 1, 3});
  cout << sl << '\n';
  MergeSort(&sl.head);
  cout << sl << '\n';

  return 0;
}
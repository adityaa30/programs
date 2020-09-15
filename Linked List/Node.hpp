#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next, *random;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->random = NULL;
  }

  friend ostream &operator<<(ostream &os, const Node &node) {
    return os << node.data;
  }
};

struct SLL {
  Node *head = NULL, *last = NULL;
  SLL() {}

  SLL(vector<int> data) { this->Add(data); }

  SLL(Node *root) {
    while (root != NULL) {
      Add(root);
      root = root->next;
    }
  }

  void Add(int data) {
    if (this->head == NULL) {
      this->head = new Node(data);
      this->last = this->head;
    } else {
      this->last->next = new Node(data);
      this->last = this->last->next;
    }
  }

  void Add(vector<int> data) {
    for (int val : data)
      this->Add(val);
  }

  void Add(Node *node) {
    this->last->next = node;
    this->last = this->last->next;
  }

  void Add(SLL sll) {
    Node *curr = sll.head;
    while (curr != NULL) {
      Add(curr);
      curr = curr->next;
    }
  }

  friend ostream &operator<<(ostream &os, const SLL &sll) {
    os << "SLL(";
    Node *curr = sll.head;
    while (curr != NULL) {
      os << *curr << " ";
      curr = curr->next;
    }
    os << ")";
    return os;
  }
};

void PrintList(Node *head) {
  while (head != NULL) {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << '\n';
}

void PrintListRandom(Node *head) {
  while (head != NULL) {
    if (head->random != NULL) {
      cout << '(' << head->data << ',' << head->random->data << ") ";
    } else {
      cout << '(' << head->data << ",X) ";
    }

    head = head->next;
  }
  cout << '\n';
}
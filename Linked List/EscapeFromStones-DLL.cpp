// adityaa30
// CodeForces - https://codeforces.com/problemset/problem/264/A
#include <bits/stdc++.h>
#define int long long int
#define print1(a) cout << '(' << #a << '=' << a << ')';
#define print2(a, b)                                                           \
  cout << '(' << #a << '=' << a << ',' << #b << '=' << b << ')';
#define print3(a, b, c)                                                        \
  cout << '(' << #a << '=' << a << ',' << #b << '=' << b << ',' << #c << '='   \
       << c << ')';
#define print(it)                                                              \
  cout << #it << " -> ";                                                       \
  for (auto __x__ : it)                                                        \
    cout << __x__ << ' ';                                                      \
  cout << '\n';
using namespace std;
const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1, 1, 1, -1, -1};
int PosY[] = {1, 0, -1, 0, 1, -1, 1, -1};

struct DLL {
  struct Node {
    int data;
    Node *next, *prev;
    Node(int data) {
      this->data = data;
      this->next = NULL;
      this->prev = NULL;
    }
  };
  Node *last;
  int curr;
  DLL() {
    this->curr = 1;
    Node *node = new Node(this->curr);
    this->last = node;
  }

  void AddLeft() {
    this->curr += 1;

    // 1 4 2 3
    Node *node = new Node(this->curr);
    node->prev = this->last->prev;
    node->next = this->last;

    if (this->last->prev != NULL) {
      this->last->prev->next = node;
    }

    this->last->prev = node;
    this->last = node;
  }

  void AddRight() {
    this->curr += 1;

    // 1 2 4 3
    Node *node = new Node(this->curr);
    node->next = this->last->next;
    node->prev = this->last;

    if (this->last->next != NULL) {
      this->last->next->prev = node;
    }

    this->last->next = node;
    this->last = node;
  }

  Node *GetHead() {
    Node *ptr = last;
    while (ptr->prev != NULL) {
      ptr = ptr->prev;
    }

    return ptr;
  }
};

void Solve() {
  // Start here
  string s;
  cin >> s;
  DLL *l = new DLL();

  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == 'l') {
      l->AddLeft();
    } else {
      l->AddRight();
    }
  }

  DLL::Node *head = l->GetHead();
  while (head != NULL) {
    cout << head->data << '\n';
    head = head->next;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  //   cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve();
  }

  return 0;
}
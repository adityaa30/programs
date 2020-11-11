#include <bits/stdc++.h>
using namespace std;

struct Expression {
  string left, right;

  void Init() {
    string expr;
    getline(cin >> ws, expr);
    int idx = expr.find("=");
    this->left = expr.substr(0, idx);
    this->right = expr.substr(idx + 1);
  }

  bool operator==(const Expression &expr) {
    return expr.left == this->left && expr.right == this->right;
  }

  friend ostream &operator<<(ostream &os, const Expression &expr) {
    return os << expr.left << " = " << expr.right;
  }
};

int32_t main() {
  int n;
  cin >> n;

  vector<Expression> expressions(n), pr;
  for (auto &expr : expressions) {
    expr.Init();
  }

  cout << "Intermediate Code: \n";
  for (auto &expr : expressions) {
    cout << expr << '\n';
  }

  // Dead Code Elimination
  for (int i = 0; i < n - 1; ++i) {
    string currLeft = expressions[i].left;
    for (int j = 0; j < n; ++j) {
      int idx = expressions[j].right.find(currLeft);
      if (idx != string::npos) {
        pr.push_back(expressions[i]);
      }
    }
  }

  pr.push_back(expressions.back());
  cout << "\n\nAfter Dead Code Elimination: \n";
  for (auto &expr : pr) {
    cout << expr << "\n";
  }

  // Sub Expression Elimination
  for (int k = 0; k < pr.size(); ++k) {
    for (int j = k + 1; j < pr.size(); ++j) {
      int idx = pr[k].right.find(pr[j].right);
      if (idx != string::npos) {
        string temp = pr[j].left;
        pr[j].left = pr[k].left;
        for (int i = 0; i < pr.size(); ++i) {
          int idx2 = pr[i].right.find(temp);
          if (idx2 != string::npos) {
            pr[i].right.erase(idx2, pr[i].right.length());
            pr[i].right += pr[k].left;
          }
        }
      }
    }
  }

  cout << "\n\nEliminate Common Expression: \n";
  for (auto &expr : pr) {
    cout << expr << '\n';
  }

  for (int i = 0; i < pr.size(); ++i) {
    for (int j = i + 1; j < pr.size(); ++j) {
      if (pr[i] == pr[j]) {
        pr[j].left = "";
        pr[j].right = "";
      }
    }
  }

  cout << "\n\nOptimized Code: \n";
  for (auto &expr : pr) {
    if (expr.left != "" && expr.right != "") {
      cout << expr << "\n";
    }
  }
}
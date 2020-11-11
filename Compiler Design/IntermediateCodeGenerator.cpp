#include <bits/stdc++.h>
using namespace std;

inline bool isAlphabet(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int GetPrecedence(char c) {
  if (c == '^')
    return 6;
  else if (c == '*' || c == '/')
    return 5;
  else if (c == '+' || c == '-')
    return 4;
  else if (c == '>' || c == '<')
    return 3;
  else if (c == '&')
    return 2;
  else if (c == '|')
    return 1;
  else
    return -1;
}

string InfixToPostfix(const string &expression) {
  stack<char> s;
  string postfix = "";
  for (char c : expression) {
    if (isAlphabet(c)) {
      postfix += c;
    } else if (c == '(') {
      s.push('(');
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
      }
      if (!s.empty() && s.top() == '(') {
        s.pop();
      }
    } else {
      while (!s.empty() && GetPrecedence(c) <= GetPrecedence(s.top())) {
        postfix += s.top();
        s.pop();
      }
      s.push(c);
    }
  }

  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  return postfix;
}

vector<string> GetThreeAddressCode(const string &expression) {
  int counter = 1;
  vector<string> addrCode;
  string postfix = InfixToPostfix(expression);
  stack<string> s;
  for (char c : postfix) {
    if (isAlphabet(c)) {
      string chr = "";
      chr += c;
      s.push(chr);
    } else {
      string op2 = s.top();
      s.pop();
      string op1 = s.top();
      s.pop();
      string code = "t" + to_string(counter);
      s.push(code); // Add this variable to stack
      counter++;
      code += " = ";
      code += op1;
      code += c;
      code += op2;
      addrCode.push_back(code);
    }
  }
  return addrCode;
}

int32_t main() {
  string expr;
  cout << "Expression: ";
  cin >> expr;
  auto addrCode = GetThreeAddressCode(expr);
  cout << "Three Address Code: \n";
  for (auto code : addrCode) {
    cout << code << '\n';
  }
  return 0;
}

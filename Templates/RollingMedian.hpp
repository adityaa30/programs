#pragma once
#include <bits/stdc++.h>
using namespace std;

class RollingMedian {
  multiset<int> mn;               // Right Half
  multiset<int, greater<int>> mx; // Left Half

public:
  void insert(int x) {
    mx.insert(x);
    mn.insert(*mx.begin());
    mx.erase(mx.begin());

    if (mx.size() < mn.size()) {
      mx.insert(*mn.begin());
      mn.erase(mn.begin());
    }
  }

  bool erase(int x) {
    if (mx.find(x) != mx.end()) {
      mx.erase(mx.find(x));
      if (mx.size() < mn.size()) {
        mx.insert(*mn.begin());
        mn.erase(mn.begin());
      }

      return true;
    } else if (mn.find(x) != mn.end()) {
      mn.erase(mn.find(x));
      if (mx.size() - mn.size() == 2) {
        mn.insert(*mx.begin());
        mx.erase(mx.begin());
      }

      return true;
    }
    return false;
  }

  // Here if (mx.size() == mn.size()) => Even length
  // We right now take the minimum element
  int GetMedian() { return *mx.begin(); }
};
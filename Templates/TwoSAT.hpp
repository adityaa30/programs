#pragma once
#include <KosarajuSCC.hpp>
#include <bits/stdc++.h>
using namespace std;

class TwoSAT {
private:
  int num_terms;
  vector<vector<int>> adj;
  KosarajuSCC *scc;

public:
  TwoSAT(int num_terms) : num_terms(num_terms) {
    adj = vector<vector<int>>(num_terms * 2);
  }

  int negate(int x) { return x + (x < num_terms ? num_terms : -num_terms); }
  int abs(int x) { return (x < num_terms ? x : (x - num_terms)); }
  void force_var(int x) {
    // same as add_or(x, x)
    adj[negate(x)].push_back(x);
  }
  void add_edge(int x, int y) { adj[x].push_back(y); }

  void add_or(int x, int y) {
    // (x | y) => (-x -> y) & (-y -> x)
    assert(abs(x) < num_terms);
    assert(abs(y) < num_terms);
    add_edge(negate(x), y);
    add_edge(negate(y), x);
  }

  void add_xor(int x, int y) {
    // (x xor y) => (x | y) & (~x | ~y)
    add_or(x, y);
    add_or(negate(x), negate(y));
  }

  vector<vector<int>> get() { return this->adj; }

  bool run() {
    scc = new KosarajuSCC(adj);
    for (int i = 0; i < num_terms; ++i) {
      if (scc->group[i] == scc->group[negate(i)]) {
        // Contradiction
        return false;
      }
    }

    return true;
  }
};
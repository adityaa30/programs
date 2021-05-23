#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> GetAdjacencyList(vector<array<int, 2>> edges,
                                     bool undirected = true) {
  int V = 0;
  for (auto &edge : edges)
    V = max({V, edge[0], edge[1]});

  vector<vector<int>> adj(V + 1);
  for (auto &edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    if (undirected) {
      adj[edge[1]].push_back(edge[0]);
    }
  }
  return adj;
} 
#include <bits/stdc++.h>
#define li long long int
using namespace std;

void PrintKDistanceNodes(li curr, vector<vector<li>> adj, bool *visited, li k) {
    if(!visited[curr]) {
        if(k == 0) cout << curr + 1 << ' ';
        visited[curr] = true;
        for(li child : adj[curr]) if(!visited[child] && k > 0) PrintKDistanceNodes(child, adj, visited, k - 1);
    }
}

int main() {
    li a, b, numNodes, numEdges;
    cin >> numNodes >>  numEdges;
    vector<vector<li>> adj(numNodes);
    while(numEdges--) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    bool visited[numNodes] = {false};
    PrintKDistanceNodes(2 - 1, adj, visited, 2);
    return 0;
}
#include <bits/stdc++.h>
#define li long long int
using namespace std;

void DFS(li curr, vector<vector<li>> adj, bool *visited) {
    if (!visited[curr]) {
        cout << curr + 1 << ' ';
        visited[curr] = true;
        for(auto child : adj[curr]) {
            if(!visited[child]) DFS(child, adj, visited);
        }
    }
} 

void BFS(li src, vector<vector<li>> adj) {
    bool visited[adj.size()] = {false};
    queue<li> q;
    li curr;
    q.push(src);

    while(!q.empty()) {
        curr = q.front();
        q.pop();

        cout << curr + 1 << ' ';
        visited[curr] = true;
        for(li child : adj[curr]) if(!visited[child]) q.push(child);
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
    cout << "DFS: "; DFS(0, adj, visited); cout << endl;
    cout << "BFS: "; BFS(0, adj); cout << endl;
    return 0;
}
#include <bits/stdc++.h>
#define li long long int
using namespace std;

class Graph {
    li V;
    list<li> *adj;
    public:
    Graph(li V) {
        this->V = V;
        adj = new list<li>[V];
    }

    void addEdge(li v, li w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    pair<li, li> bfs(li u) {
        li dis[V];
        memset(dis, -1, sizeof(dis));

        queue<li> q;
        q.push(u);

        dis[u] = 0;

        while(!q.empty()) {
            li t = q.front();
            q.pop();

            for(auto child : adj[t]) {
                if(dis[child] == -1) {
                    q.push(child);
                    dis[child] = dis[t] + 1;
                }
            }
        }

        li maxDis = 0;
        li nodeIdx = 0;

        for(li i = 0; i < V; ++i) {
            if (dis[i] > maxDis) {
                maxDis = dis[i];
                nodeIdx = i;
            }
        }

        return make_pair(nodeIdx, maxDis);

    }

    li longestPathLength() {
        pair<li, li> temp1, temp2;

        temp1 = bfs(0);
        temp2 = bfs(temp1.first);

        return temp2.second;
    }

};

int main() {
    li v, temp1, temp2;
    cin >> v;
    Graph graph(v);
    for(li i = 0; i < v - 1; ++i) {
        cin >> temp1 >> temp2;
        graph.addEdge(temp1, temp2);
    }

    cout << "Length of longest path: " << graph.longestPathLength() << endl;
    return 0;
}
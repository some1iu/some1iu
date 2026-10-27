#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void bfs(int start) {
    queue<int> q;
    vis.assign(n, 0);
    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    adj.resize(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS order: ";
    bfs(start);
    cout << endl;

    vis.assign(n, 0);
    cout << "DFS order: ";
    dfs(start);
    cout << endl;

    return 0;
}

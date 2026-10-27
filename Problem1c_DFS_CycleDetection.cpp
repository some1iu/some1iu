#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, path;

bool dfsDirected(int u) {
    vis[u] = 1;
    path[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfsDirected(v)) {
                return true;
            }
        } else if (path[v]) {
            return true;
        }
    }

    path[u] = 0;
    return false;
}

bool dfsUndirected(int u, int parent) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfsUndirected(v, u)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int type;
    cout << "Enter 1 for directed graph and 0 for undirected graph: ";
    cin >> type;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    adj.resize(n);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (type == 0) {
            adj[v].push_back(u);
        }
    }

    vis.assign(n, 0);
    path.assign(n, 0);
    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (type == 1) {
                if (dfsDirected(i)) {
                    cycle = true;
                    break;
                }
            } else {
                if (dfsUndirected(i, -1)) {
                    cycle = true;
                    break;
                }
            }
        }
    }

    if (cycle) {
        cout << "Cycle is present" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}

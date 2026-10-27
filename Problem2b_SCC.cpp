#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, radj;
vector<int> vis, order;

void dfs1(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }

    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    cout << u << " ";

    for (int v : radj[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    adj.resize(n);
    radj.resize(n);
    cout << "Enter directed edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vis.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    vis.assign(n, 0);
    int count = 0;
    cout << "Strongly connected components are:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (!vis[u]) {
            count++;
            cout << "Component " << count << ": ";
            dfs2(u);
            cout << endl;
        }
    }

    cout << "Total number of components: " << count << endl;

    return 0;
}

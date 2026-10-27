#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, path;
stack<int> st;
bool cycle = false;

void dfs(int u) {
    vis[u] = 1;
    path[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        } else if (path[v]) {
            cycle = true;
        }
    }

    path[u] = 0;
    st.push(u);
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    adj.resize(n);
    cout << "Enter directed edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vis.assign(n, 0);
    path.assign(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    if (cycle) {
        cout << "Graph has a cycle, topological order is not possible" << endl;
        return 0;
    }

    cout << "Topological order: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

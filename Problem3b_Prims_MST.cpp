#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<int> inMST(n, 0);
    key[start] = 0;

    int total = 0;
    cout << "Edges selected for MST:" << endl;

    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "MST is not possible" << endl;
            return 0;
        }

        inMST[u] = 1;
        total += key[u];

        if (parent[u] != -1) {
            cout << parent[u] << " - " << u << " : " << key[u] << endl;
        }

        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Total weight of MST: " << total << endl;

    return 0;
}

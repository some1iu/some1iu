#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> disc, finish, color;
int timer1 = 0;

void dfs(int u) {
    color[u] = 1;
    disc[u] = ++timer1;

    for (int v : adj[u]) {
        cout << "Edge " << u << " -> " << v << " : ";
        if (color[v] == 0) {
            cout << "Tree edge" << endl;
            dfs(v);
        } else if (color[v] == 1) {
            cout << "Back edge" << endl;
        } else if (disc[u] < disc[v]) {
            cout << "Forward edge" << endl;
        } else {
            cout << "Cross edge" << endl;
        }
    }

    color[u] = 2;
    finish[u] = ++timer1;
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

    disc.assign(n, 0);
    finish.assign(n, 0);
    color.assign(n, 0);

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    cout << endl;
    cout << "Vertex  Discovery  Finishing" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "       " << disc[i] << "          " << finish[i] << endl;
    }

    return 0;
}

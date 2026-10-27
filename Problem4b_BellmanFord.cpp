#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges;
    cout << "Enter directed edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    int x = -1;
    for (Edge e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            x = e.v;
            parent[e.v] = e.u;
            break;
        }
    }

    if (x != -1) {
        cout << "Negative weight cycle is present" << endl;

        int y = x;
        for (int i = 0; i < n; i++) {
            y = parent[y];
            if (y == -1) {
                break;
            }
        }

        if (y != -1) {
            vector<int> cycle;
            int cur = y;
            do {
                cycle.push_back(cur);
                cur = parent[cur];
            } while (cur != -1 && cur != y);

            reverse(cycle.begin(), cycle.end());
            cout << "Cycle: ";
            for (int v : cycle) {
                cout << v << " -> ";
            }
            cout << cycle[0] << endl;
        }
        return 0;
    }

    cout << "Shortest distance from source " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";
        if (dist[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}

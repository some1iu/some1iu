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

    int source, target;
    cout << "Enter source and target vertex: ";
    cin >> source >> target;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u]) {
            continue;
        }

        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
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

    if (dist[target] == INT_MAX) {
        cout << "No path to target vertex " << target << endl;
        return 0;
    }

    vector<int> path;
    int cur = target;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path to " << target << ": ";
    for (int i = 0; i < (int)path.size(); i++) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << path[i];
    }
    cout << endl;
    cout << "Distance: " << dist[target] << endl;

    return 0;
}

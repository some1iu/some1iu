#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> cap(n, vector<int>(n, 0));
    vector<vector<int>> cost(n, vector<int>(n, 0));

    cout << "Enter directed edges (u v capacity cost):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        cap[u][v] += c;
        cost[u][v] = w;
        cost[v][u] = -w;
    }

    int source, sink;
    cout << "Enter source and sink: ";
    cin >> source >> sink;

    int maxFlow = 0;
    int totalCost = 0;
    int step = 1;

    while (true) {
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        dist[source] = 0;

        for (int i = 0; i < n; i++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (cap[u][v] > 0 && dist[u] != INT_MAX) {
                        if (dist[u] + cost[u][v] < dist[v]) {
                            dist[v] = dist[u] + cost[u][v];
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        if (dist[sink] == INT_MAX) {
            break;
        }

        int bottleneck = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, cap[u][v]);
        }

        vector<int> path;
        for (int v = sink; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Augmenting path " << step << ": ";
        for (int i = 0; i < (int)path.size(); i++) {
            if (i > 0) {
                cout << " -> ";
            }
            cout << path[i];
        }
        cout << "  Bottleneck: " << bottleneck;
        cout << "  Cost per unit: " << dist[sink] << endl;
        step++;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= bottleneck;
            cap[v][u] += bottleneck;
        }

        maxFlow += bottleneck;
        totalCost += bottleneck * dist[sink];
    }

    cout << "Maximum flow: " << maxFlow << endl;
    cout << "Minimum total cost: " << totalCost << endl;

    return 0;
}

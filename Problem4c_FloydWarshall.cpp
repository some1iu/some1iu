#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    cout << "Enter directed edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << setw(6) << "INF";
            } else {
                cout << setw(6) << dist[i][j];
            }
        }
        cout << endl;
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Negative weight cycle is present" << endl;
        cout << "Vertices in negative cycle: ";
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else {
        cout << "No negative weight cycle is present" << endl;
    }

    return 0;
}

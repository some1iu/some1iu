#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> cap, res;

bool bfs(int s, int t, vector<int> &parent) {
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!vis[v] && res[u][v] > 0) {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return vis[t];
}

int main() {
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    cap.assign(n, vector<int>(n, 0));
    cout << "Enter directed edges (u v capacity):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cap[u][v] += c;
    }

    int source, sink;
    cout << "Enter source and sink: ";
    cin >> source >> sink;

    res = cap;
    vector<int> parent(n);
    int maxFlow = 0;
    int step = 1;

    while (bfs(source, sink, parent)) {
        int bottleneck = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, res[u][v]);
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
        cout << "  Bottleneck: " << bottleneck << endl;
        step++;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            res[u][v] -= bottleneck;
            res[v][u] += bottleneck;
        }

        maxFlow += bottleneck;
    }

    cout << "Maximum flow: " << maxFlow << endl;

    cout << "Final residual network:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << res[i][j];
        }
        cout << endl;
    }

    vector<int> vis(n, 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (!vis[v] && res[u][v] > 0) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    cout << "Minimum cut:" << endl;
    cout << "S side: ";
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "T side: ";
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    int cutCapacity = 0;
    cout << "Cut edges:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cap[i][j] > 0 && vis[i] && !vis[j]) {
                cout << i << " -> " << j << " : " << cap[i][j] << endl;
                cutCapacity += cap[i][j];
            }
        }
    }
    cout << "Capacity of minimum cut: " << cutCapacity << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> res;

bool bfs(int s, int t, vector<int> &parent) {
    vector<int> vis(N, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N; v++) {
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
    int L, R, e;
    cout << "Enter number of left vertices, right vertices and edges: ";
    cin >> L >> R >> e;

    vector<pair<int, int>> edges;
    cout << "Enter edges (left right):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int source = 0;
    N = L + R + 2;
    int sink = N - 1;

    res.assign(N, vector<int>(N, 0));

    for (int i = 0; i < L; i++) {
        res[source][1 + i] = 1;
    }
    for (int j = 0; j < R; j++) {
        res[1 + L + j][sink] = 1;
    }
    for (auto p : edges) {
        int leftNode = 1 + p.first;
        int rightNode = 1 + L + p.second;
        res[leftNode][rightNode] = 1;
    }

    vector<int> parent(N);
    int maxFlow = 0;

    while (bfs(source, sink, parent)) {
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            res[u][v] -= 1;
            res[v][u] += 1;
        }
        maxFlow++;
    }

    cout << "Maximum matching size: " << maxFlow << endl;
    cout << "Matched pairs:" << endl;
    for (auto p : edges) {
        int leftNode = 1 + p.first;
        int rightNode = 1 + L + p.second;
        if (res[rightNode][leftNode] == 1) {
            cout << "Left " << p.first << " - Right " << p.second << endl;
        }
    }

    return 0;
}

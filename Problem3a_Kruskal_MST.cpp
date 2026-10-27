#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> parent;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int total = 0;
    int count = 0;

    cout << "Edges selected for MST:" << endl;
    for (Edge e : edges) {
        int pu = findParent(e.u);
        int pv = findParent(e.v);

        if (pu != pv) {
            parent[pu] = pv;
            total += e.w;
            count++;
            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }

    if (count == n - 1) {
        cout << "Total weight of MST: " << total << endl;
    } else {
        cout << "MST is not possible" << endl;
    }

    return 0;
}

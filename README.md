# Graph Algorithms Programs in C++

One separate C++ file is made for every problem. Vertices are numbered
from 0 to n-1 in all programs.

## Files

| File | Problem |
|---|---|
| Problem1a_BFS_DFS.cpp | 1(a) BFS and DFS traversal |
| Problem1b_DFS_Times_EdgeClassification.cpp | 1(b) Discovery / finishing times and edge classification |
| Problem1c_DFS_CycleDetection.cpp | 1(c) Cycle detection in directed and undirected graph |
| Problem2a_TopologicalSort.cpp | 2(a) Topological ordering of a DAG |
| Problem2b_SCC.cpp | 2(b) Strongly connected components (Kosaraju) |
| Problem3a_Kruskal_MST.cpp | 3(a) MST by Kruskal |
| Problem3b_Prims_MST.cpp | 3(b) MST by Prim |
| Problem4a_Dijkstra.cpp | 4(a) Dijkstra with path reconstruction |
| Problem4b_BellmanFord.cpp | 4(b) Bellman-Ford with negative cycle detection |
| Problem4c_FloydWarshall.cpp | 4(c) Floyd-Warshall all pairs shortest paths |
| Problem5a_MaxFlow.cpp | 5(a) Max flow (Edmonds-Karp), residual network and min cut |
| Problem5b_BipartiteMatching.cpp | 5(b) Bipartite matching using max flow |
| Problem5c_MinCostMaxFlow.cpp | 5(c) Min cost max flow |

## How to compile and run

```
g++ -std=c++17 Problem1a_BFS_DFS.cpp -o p1a
./p1a
```

Give the input as shown in the samples below.

## Sample Inputs and Outputs

### Problem 1(a) BFS and DFS

Input:
```
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0
```
Output:
```
BFS order: 0 1 2 3 4 5
DFS order: 0 1 3 5 4 2
```

### Problem 1(b) DFS times and edge classification

Input:
```
6 8
0 1
0 3
1 4
2 4
2 5
3 1
4 3
5 5
```
Output:
```
Edge 0 -> 1 : Tree edge
Edge 1 -> 4 : Tree edge
Edge 4 -> 3 : Tree edge
Edge 3 -> 1 : Back edge
Edge 0 -> 3 : Forward edge
Edge 2 -> 4 : Cross edge
Edge 2 -> 5 : Tree edge
Edge 5 -> 5 : Back edge

Vertex  Discovery  Finishing
0       1          8
1       2          7
2       9          12
3       4          5
4       3          6
5       10         11
```

### Problem 1(c) Cycle detection

Directed graph with cycle. First enter 1 for directed and 0 for undirected.

Input:
```
1
4 4
0 1
1 2
2 3
3 1
```
Output:
```
Cycle is present
```

Undirected graph without cycle:
```
0
4 3
0 1
1 2
2 3
```
Output:
```
Cycle is not present
```

### Problem 2(a) Topological sort

Input:
```
6 6
5 2
5 0
4 0
4 1
2 3
3 1
```
Output:
```
Topological order: 5 4 2 3 1 0
```

### Problem 2(b) Strongly connected components

Input:
```
5 5
0 2
2 1
1 0
0 3
3 4
```
Output:
```
Strongly connected components are:
Component 1: 0 1 2
Component 2: 3
Component 3: 4
Total number of components: 3
```

### Problem 3(a) Kruskal MST

Input:
```
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```
Output:
```
Edges selected for MST:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
Total weight of MST: 19
```

### Problem 3(b) Prim MST

Same graph as 3(a). Extra input is the starting vertex.

Input:
```
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
0
```
Output:
```
Edges selected for MST:
0 - 3 : 5
3 - 2 : 4
0 - 1 : 10
Total weight of MST: 19
```

Comparison with 3(a): Both Kruskal and Prim give the same MST edges
(0-3, 3-2 and 0-1) and the same total weight 19. Only the order of
selecting the edges is different. Kruskal picks the smallest edge of
the whole graph first (2-3), while Prim starts from vertex 0 and picks
the smallest edge going out of the tree (0-3). The total weight of MST
is always the same from both methods.

### Problem 4(a) Dijkstra

Graph is taken as undirected in this program.

Input:
```
5 7
0 1 2
0 2 4
1 2 1
1 3 7
2 3 2
2 4 3
3 4 1
0 4
```
Output:
```
Shortest distance from source 0:
Vertex 0 : 0
Vertex 1 : 2
Vertex 2 : 3
Vertex 3 : 5
Vertex 4 : 6
Shortest path to 4: 0 -> 1 -> 2 -> 4
Distance: 6
```

### Problem 4(b) Bellman-Ford

Input:
```
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
```
Output:
```
Shortest distance from source 0:
Vertex 0 : 0
Vertex 1 : -1
Vertex 2 : 2
Vertex 3 : -2
Vertex 4 : 1
```

Input with negative cycle:
```
3 3
0 1 1
1 2 -1
2 0 -1
0
```
Output:
```
Negative weight cycle is present
Cycle: 2 -> 0 -> 1 -> 2
```

### Problem 4(c) Floyd-Warshall

Input:
```
4 4
0 1 5
0 3 10
1 2 2
2 3 1
```
Output:
```
Distance matrix:
     0     5     7     8
   INF     0     2     3
   INF   INF     0     1
   INF   INF   INF     0
No negative weight cycle is present
```

If any diagonal value dist[i][i] becomes negative, the program prints
"Negative weight cycle is present" and the vertices of the cycle.

### Problem 5(a) Max flow

Input:
```
6 9
0 1 16
0 2 13
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5
```
Output:
```
Augmenting path 1: 0 -> 1 -> 3 -> 5  Bottleneck: 12
Augmenting path 2: 0 -> 2 -> 4 -> 5  Bottleneck: 4
Augmenting path 3: 0 -> 2 -> 4 -> 3 -> 5  Bottleneck: 7
Maximum flow: 23
Final residual network:
   0   4   2   0   0   0
  12   0   0   0   0   0
  11   4   0   0   3   0
   0  12   9   0   7   1
   0   0  11   0   0   0
   0   0   0  19   4   0
Minimum cut:
S side: 0 1 2 4
T side: 3 5
Cut edges:
1 -> 3 : 12
4 -> 3 : 7
4 -> 5 : 4
Capacity of minimum cut: 23
```

### Problem 5(b) Bipartite matching

Left vertices are numbered 0 to L-1 and right vertices are numbered
0 to R-1. The program adds a source and a sink and makes it a flow
network with capacity 1 on every edge.

Input:
```
4 4 7
0 0
0 1
1 0
2 1
2 2
3 2
3 3
```
Output:
```
Maximum matching size: 4
Matched pairs:
Left 0 - Right 1
Left 1 - Right 0
Left 2 - Right 2
Left 3 - Right 3
```

### Problem 5(c) Min cost max flow

Input:
```
4 5
0 1 2 1
0 2 2 3
1 3 2 2
2 3 2 1
1 2 1 1
0 3
```
Output:
```
Augmenting path 1: 0 -> 1 -> 3  Bottleneck: 2  Cost per unit: 3
Augmenting path 2: 0 -> 2 -> 3  Bottleneck: 2  Cost per unit: 4
Maximum flow: 4
Minimum total cost: 14
```

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure for an edge in a graph
struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Union-Find data structure to detect cycles in Kruskal's algorithm
class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Prim's Algorithm for Minimum Spanning Tree (MST)
void primsAlgorithm(int vertices, vector<vector<int>>& graph) {
    /*
    Steps for Prim's Algorithm:
    1. Start with an arbitrary vertex (usually vertex 0).
    2. Set the key value for this vertex as 0, and all others to infinity.
    3. For every vertex, find the minimum weight edge connecting it to the vertices already in the MST.
    4. Add the vertex with the minimum weight edge to the MST.
    5. Repeat until all vertices are included in the MST.
    */
    
    vector<int> parent(vertices, -1); // To store parent of each vertex in the MST
    vector<int> key(vertices, INT_MAX); // Stores the minimum weight edge for each vertex
    vector<bool> inMST(vertices, false); // To track vertices included in MST

    key[0] = 0; // Start from vertex 0
    for (int count = 0; count < vertices - 1; ++count) {
        int u = -1;
        // Find the vertex with the minimum key value not yet included in MST
        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true; // Include vertex u in MST

        // Update key values and parent for vertices adjacent to u
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Output the MST edges
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << " with weight " << graph[i][parent[i]] << endl;
    }
}

// Kruskal's Algorithm for Minimum Spanning Tree (MST)
void kruskalAlgorithm(int vertices, vector<Edge>& edges) {
    /*
    Steps for Kruskal's Algorithm:
    1. Sort all the edges in the graph by their weights in increasing order.
    2. Initialize a union-find data structure to detect cycles.
    3. Start adding edges to the MST. For each edge, check if it forms a cycle using union-find.
    4. If it doesn't form a cycle, include it in the MST.
    5. Repeat until we have included enough edges (vertices - 1).
    */
    
    UnionFind uf(vertices); // Union-Find data structure to detect cycles
    vector<Edge> mst; // To store the edges of the MST

    // Sort edges by weight in ascending order
    for (int i = 0; i < edges.size(); ++i) {
        for (int j = i + 1; j < edges.size(); ++j) {
            if (edges[i].weight > edges[j].weight) {
                swap(edges[i], edges[j]);
            }
        }
    }

    // Process each edge and add it to the MST if it doesn't form a cycle
    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst.push_back(edge);
        }
    }

    // Output the MST edges
    for (Edge edge : mst) {
        cout << edge.u << " - " << edge.v << " with weight " << edge.weight << endl;
    }
}

// Dijkstra's Algorithm for Shortest Path
void dijkstraAlgorithm(int vertices, vector<vector<int>>& graph, int start) {
    /*
    Steps for Dijkstra's Algorithm:
    1. Initialize all distances to infinity, except for the starting vertex, which is set to 0.
    2. Mark all vertices as unvisited.
    3. For the current vertex, check its adjacent vertices and update their distances if a shorter path is found.
    4. Mark the current vertex as visited and move to the unvisited vertex with the smallest distance.
    5. Repeat until all vertices are visited.
    */
    
    vector<int> dist(vertices, INT_MAX); // Distance array to store shortest paths
    vector<bool> visited(vertices, false); // To track visited vertices
    dist[start] = 0; // Distance from the start vertex to itself is 0

    for (int count = 0; count < vertices - 1; ++count) {
        int u = -1;
        // Find the vertex with the smallest distance that hasn't been visited
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        visited[u] = true; // Mark vertex u as visited

        // Update distances for the adjacent vertices of u
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output the shortest path distances from the start vertex
    for (int i = 0; i < vertices; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << ": INF" << endl; // If no path exists
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int vertices = 5;

    // Graph representation for Prim's and Dijkstra's (Adjacency matrix)
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // List of edges for Kruskal's (Edge list format)
    vector<Edge> edges = {
        Edge(0, 1, 2), Edge(0, 3, 6), Edge(1, 2, 3), Edge(1, 3, 8), Edge(1, 4, 5),
        Edge(2, 4, 7), Edge(3, 4, 9)
    };

    // Run Prim's Algorithm
    cout << "Prim's Algorithm (MST):\n";
    primsAlgorithm(vertices, graph);

    // Run Kruskal's Algorithm
    cout << "\nKruskal's Algorithm (MST):\n";
    kruskalAlgorithm(vertices, edges);

    // Run Dijkstra's Algorithm
    cout << "\nDijkstra's Algorithm (Shortest Path from vertex 0):\n";
    dijkstraAlgorithm(vertices, graph, 0); // Start from vertex 0

    return 0;
}

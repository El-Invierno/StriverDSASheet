#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    // Adjacency Matrix:
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0)); 
    for(int i = 0; i < m; i++) // m lines correspond to the list of edges bw the nodes.
    {
        int u, v;
        cin >> u >> v;
        // Both the below statements are true for undirected graph.        
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    // Space Complexity of a Matrix is O(n^2).


    // Adjacency List:
    vector<int> adj[n + 1]; // No weights in the graph.
    vector<pair<int,int>>adj1[n + 1]; // Weighted graph.
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Space Complexity of an adj list if undirected graph: O(2E).
    // Space Complexity of an adj list if directed graph: O(E).


    return 0;
}
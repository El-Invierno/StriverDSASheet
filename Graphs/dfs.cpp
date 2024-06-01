public:
    
    void dfs(int node, int vis[], vector<int>adj[], vector<int>&res)
    {
        vis[node] = 1;
        res.push_back(node);
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                dfs(x,vis,adj,res);
            }
        }
    }
    
    // Space Complex: O(n)
    // Time Complex: O(n) + O(2e) [undirected graph] or O(e) [directed graph.]
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int>res;
        int start = 0;
        int vis[n] = {0};
        dfs(start,vis,adj,res);
        return res;
    }
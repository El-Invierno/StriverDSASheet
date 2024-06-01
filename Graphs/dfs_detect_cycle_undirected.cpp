bool dfs(int i, int parent, vector<int>&vis,vector<int> adj[])
    {
        vis[i] = 1;
        for(auto x : adj[i])
        {
            if(!vis[x])
            {
                if (dfs(x,i,vis,adj))
                {
                    return true;
                }
            }
            else if(x != parent)
            {
                return true;
            }
        }
        return false;
    }
    
    // Time complex: O(N + 2E) + O(N).
    // Space complex: O(N) + O(N)


    bool isCycle(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,vis,adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
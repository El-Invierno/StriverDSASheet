// Using BFS.

// Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        
        int vis[n] = {0};
        queue<pair<int,int>>q; // cur,parent
        
        for(int i = 0; i < n; i++) // Keep into account the disconnected components of the graph as well.
        {
            if(!vis[i])
            {
                int start = i;
                q.push({start,0});
                vis[start] = 1;
                
                while(!q.empty())
                {
                    int temp = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto x : adj[temp])
                    {
                        if(!vis[x])
                        {
                            q.push({x,temp});
                            vis[x] = 1;
                        }
                        else if(x != parent)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
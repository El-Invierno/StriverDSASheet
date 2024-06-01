vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        
        int vis[n] = {0};
        vector<int>res;
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        
        // We have to visit the elements that are pushed to the queue.
        
        // Space Complex: O(3n)
        // Time Complex: O(n) 2 + O(2E) OR O(E) for loop runs for all neighboring nodes of every node.
        
        while(!q.empty())
        {
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            for(auto x : adj[temp])
            {
                if(!vis[x])
                {
                    q.push(x);   
                    vis[temp] = 1;
                }
            }
        }
        return res;
    }
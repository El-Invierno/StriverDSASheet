class Solution {

private: 
    void dfs(int start, vector<int>&vis, vector<vector<int>>& arr)
    {
        vis[start] = 1;
        for(int i = 0; i < arr.size(); i++)
        {   
            if(arr[start][i] == 1)
            {
                if(!vis[i])
                {
                    dfs(i,vis,arr);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& arr) {
        // we are given an adjacency matrix( n + 1 )* (n + 1).
        int n = arr.size(); // == n + 1
        vector<int>vis(n,0);
        int provinces = 0;
        for(int i = 0; i < n; i++) 
        {
            if(!vis[i])
            {
                dfs(i,vis,arr);
                provinces++;
            }
        }
        return provinces;
    }
};
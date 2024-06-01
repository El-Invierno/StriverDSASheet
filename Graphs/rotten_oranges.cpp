class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q; // (r,c), time
        vector<vector<int>>vis(n, vector<int>(m, 0)); // visited matrix.

        // Time Complexity:- O(n x m)
        // Space Complexity:- O(n x m)


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) // rotten.
                {
                    q.push({{i,j},0}); // starting points in the matrix.
                    vis[i][j] = 2;
                }   
            }
        }

        int time = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc])
                {
                    q.push({{nr,nc},t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    if((vis[i][j] != 2))
                    {
                        return -1;
                    }
                }
            }
        }
        return time;
    }
};
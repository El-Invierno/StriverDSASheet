// We use BFS traversal to move level wise.

// Time complex is O(n * m).
// Space complex is O(n * m).

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>res(mat);
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q; // r,c,lev

        for(int i = 0; i < m; i++) // m rows.
        {
            for(int j = 0; j < n; j++) // n cols.
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0}); // starting points.
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int lev = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nr < m && nc >=0 && nc < n && mat[nr][nc] == 1 && !vis[nr][nc])
                {
                    res[nr][nc] = lev + 1;
                    q.push({{nr,nc},lev + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return res;
    }
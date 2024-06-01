class Solution {
 // A set of o's that are connected to an o on the boundary cannot be      encircled.

private:
    void dfs(int r,int c, vector<vector<int>>&vis,vector<vector<char>>& board)
    {
        vis[r][c] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++)
        {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] == 'O' && !vis[nr][nc])
            {
                dfs(nr,nc,vis,board);
            } 
        }
    }

// Time complex: O(nm)
// Space complex: O(nm)

public:
    void solve(vector<vector<char>>& board) {
       int n = board.size();
       int m = board[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));

       // Boundary DFS traversal.
       for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, vis, board);
            }
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                dfs(n - 1, i, vis, board);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, board);
            }
        }

       for(int i = 0; i < n; i++)
       {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'O' && !vis[i][j])
            {
                board[i][j] = 'X';
            }
        }
       }
    }
};
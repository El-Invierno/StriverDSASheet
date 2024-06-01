class Solution {
public:

    // Time and Space Complexity is O(n * m).

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>res(image); // dont change original data.
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        if(image[sr][sc] == color)
        {
            return res;
        }
        int col = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc}); //starting point
        vis[sr][sc] = 1;
        res[sr][sc] = color;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nr = r - drow[i];
                int nc = c - dcol[i];
                if(nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == col && !vis[nr][nc])
                {
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                    res[nr][nc] = color;
                }
            }
        }   
        return res;
    }
};
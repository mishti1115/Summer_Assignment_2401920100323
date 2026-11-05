class Solution {
public:
    int m, n;
    vector<vector<int>> pac, atl;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<int>>& heights) {

        vis[i][j] = 1;

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && y >= 0 && x < m && y < n &&
               !vis[x][y] && heights[x][y] >= heights[i][j]) {

                dfs(x, y, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pac.assign(m, vector<int>(n, 0));
        atl.assign(m, vector<int>(n, 0));

        // Pacific Ocean
        for(int i = 0; i < m; i++)
            dfs(i, 0, pac, heights);

        for(int j = 0; j < n; j++)
            dfs(0, j, pac, heights);

        // Atlantic Ocean
        for(int i = 0; i < m; i++)
            dfs(i, n-1, atl, heights);

        for(int j = 0; j < n; j++)
            dfs(m-1, j, atl, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
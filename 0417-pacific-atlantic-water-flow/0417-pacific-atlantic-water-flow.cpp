class Solution {
public:

   int drow[4] = {1, 0, -1, 0};
   int dcol[4] = {0, 1, 0, -1};

   void dfs(int row, int col, int n, int m, int height, vector<vector<int>>&heights, vector<vector<bool>>&vis){
        if(row < 0 || row >= n || col < 0 || col >= m)return;
        if(height > heights[row][col] || vis[row][col])return;
        vis[row][col] = true;
        for(int i = 0; i < 4; i++){
         int nrow = drow[i] + row;
         int ncol = dcol[i] + col;
         dfs(nrow, ncol, n, m, heights[row][col], heights, vis);
        }
   }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>visp(n ,vector<bool>(m, false));
        vector<vector<bool>>visa(n ,vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            dfs(i, 0, n, m, INT_MIN, heights, visp);
            dfs(i, m-1, n, m, INT_MIN, heights, visa);
        }

        for(int i = 0; i < m; i++){
            dfs(0, i, n, m, INT_MIN, heights, visp);
            dfs(n-1, i, n, m, INT_MIN, heights, visa);
        }
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visa[i][j] && visp[i][j])ans.push_back({i, j});
        }
        }
        return ans;
    }
};
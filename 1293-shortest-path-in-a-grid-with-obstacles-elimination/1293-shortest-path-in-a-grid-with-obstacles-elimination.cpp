class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>>q;
        vector<vector<int>>vis(n, vector<int>(m, INT_MAX));
        q.push({grid[0][0], {0, 0}});
        vis[0][0] = grid[0][0];
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int wall = it.first;
            int dis = it.second.first;
            int cell = it.second.second;
            int row = cell / m;
            int col = cell % m;
            if (row == n - 1 && col == m - 1)return dis;
            for (int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
               if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newWall = wall + grid[nrow][ncol];
                    if (newWall <= k && newWall < vis[nrow][ncol]) {
                        vis[nrow][ncol] = newWall;
                        int newcell = nrow * m + ncol;
                        q.push({newWall, {dis + 1, newcell}});
                    }
                }
            }
        }
        return -1;
    }
};
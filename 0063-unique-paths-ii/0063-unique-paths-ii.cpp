class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] || grid[n - 1][m - 1])return 0;
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    temp[0] = 1;
                    continue;
                }
                if (grid[i][j] == 1)temp[j] = 0;
                else {
                    int up = 0, left = 0;
                //    if (i > 0)
                        up = prev[j];
                    if (j > 0)left = temp[j - 1];
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[m - 1];
    }
};
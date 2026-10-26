class Solution {
public:
    int drow[4] = {1, 0, -1, 0};
    int dcol[4] = {0, -1, 0, 1};
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    long long sum = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        sum += grid[r][c];
                        for (int d = 0; d < 4; d++) {
                            int nr = r + drow[d];
                            int nc = c + dcol[d];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                !vis[nr][nc] && grid[nr][nc] != 0) {
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};
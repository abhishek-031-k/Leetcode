class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && dist[nrow][ncol] == INT_MAX) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));
        pq.push({dist[0][0], {0, 0}});
        best[0][0] = dist[0][0];
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int safe = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == n - 1)return safe;
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                    int newSafe = min(safe, dist[nrow][ncol]);
                    if (newSafe > best[nrow][ncol]) {
                        best[nrow][ncol] = newSafe;
                        pq.push({newSafe, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
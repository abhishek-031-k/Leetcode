class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, pair<int, int>>>dq;
          
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
       dist[0][0] = grid[0][0];
       dq.push_front({grid[0][0], {0, 0}});
       while(!dq.empty()){
         auto it = dq.front();
         dq.pop_front();
         int dis = it.first;
         int row = it.second.first;
         int col = it.second.second;
        if(dis > dist[row][col])continue;
        if(row == n - 1 && col == m - 1)return dis < health;
         for(int i = 0; i < 4; i++){
            int nrow = drow[i] + row, ncol = dcol[i] + col;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                 if(dist[nrow][ncol] > dis + grid[nrow][ncol]){
                    dist[nrow][ncol] = dis + grid[nrow][ncol];
                   if(grid[nrow][ncol] == 0)dq.push_front({dist[nrow][ncol], {nrow, ncol}});
                   else dq.push_back({dist[nrow][ncol], {nrow, ncol}});
                 }
            }
         }
       }
       return (dist[n-1][m-1] < health) ? true : false;
    }
};
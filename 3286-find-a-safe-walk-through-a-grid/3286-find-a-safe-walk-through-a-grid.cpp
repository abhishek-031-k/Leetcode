class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>pq;
          
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
       dist[0][0] = grid[0][0];
       pq.push({grid[0][0], {0, 0}});
       while(!pq.empty()){
         auto it = pq.top();
         pq.pop();
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
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                 }
            }
         }
       }
       return (dist[n-1][m-1] < health) ? true : false;
    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {entrance[0], entrance[1]}});
        vector<vector<int>>vis(n, vector<int>(m, 0));
    vis[entrance[0]][entrance[1]] = 1;
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if((row == 0 || row == n-1 || col == 0 || col == m-1) &&
             !(row == entrance[0] && col == entrance[1]))return steps;

             for(int i = 0; i < 4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && maze[nrow][ncol] == '.' && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({steps+1, {nrow, ncol}});
                }
             }
        }
        return -1;
    }
};
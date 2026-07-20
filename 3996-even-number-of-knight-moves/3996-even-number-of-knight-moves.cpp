class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if(start[0] == target[0] && start[1] == target[1])return true;
        int drow[8] = {2, 2, 1, 1, -2, -2, -1, -1};
        int dcol[8] = {1, -1, 2, -2, 1, -1, 2, -2};
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>vis(8, vector<int>(8, 0));
        q.push({{start[0], start[1]}, 0});
        while(!q.empty()){
           int row = q.front().first.first;
           int col = q.front().first.second;
           int steps = q.front().second;
           q.pop();
           vis[row][col] = 1;
           if(row == target[0] && col == target[1] && steps % 2 == 0)return true;
           for(int i = 0; i < 8; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && nrow < 8 && ncol >= 0 && ncol < 8 && vis[nrow][ncol] == 0){
                q.push({{nrow, ncol}, steps+1});
            }
           }
        }
        return false;
    }
};
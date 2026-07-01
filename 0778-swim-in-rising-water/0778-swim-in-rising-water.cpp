class DisJointSet{
public:
    vector<int> rank, size, parent;

    DisJointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node){
        if(parent[node] == node)return node;
        return parent[node] = find(parent[node]);
    }

    void unionbysize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n * n);
        vector<pair<int,int>> pos(n * n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pos[grid[i][j]] = {i, j};
            }
        }
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};
        for(int t = 0; t < n * n; t++){
            int row = pos[t].first;
            int col = pos[t].second;
            vis[row][col] = 1;
            int node = row * n + col;
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < n &&
                   vis[nrow][ncol] == 1){
                    int adjNode = nrow * n + ncol;
                    ds.unionbysize(node, adjNode);
                }
            }
            if(vis[0][0] && vis[n-1][n-1]){
                if(ds.find(0) == ds.find(n * n - 1))return t;
            }
        }
        return -1;
    }
};
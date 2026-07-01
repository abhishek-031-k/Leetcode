class DisJointSet{
public:
    vector<int> rank, size, parent;
    DisJointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v])parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n * n);
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                for(int k = 0; k < 4; k++){
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int adjNode = nrow * n + ncol;
                        ds.unionbysize(node, adjNode);
                    }
                }
            }
        }
        int ans = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                set<int> st;
                for(int k = 0; k < 4; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int node = nrow * n + ncol;
                        st.insert(ds.find(node));
                    }
                }
                int count = 0;
                for(auto it : st)count += ds.size[it];
                ans = max(ans, count + 1);
            }
        }
        if(ans == 0)return n * n;
        return ans;
    }
};
class DisJointSet{
public:
vector<int>rank, size, parent;
DisJointSet(int n){
    rank.resize(n+1, 0);
    size.resize(n+1, 1);
    parent.resize(n+1, 0);
    for(int i = 0; i <= n; i++)parent[i] = i;
}
  int find(int node){
    if(node == parent[node])return node;
    return parent[node] = find(parent[node]);
  }
  void unionbyrank(int u, int v){
    int ulp_u = find(u);
    int ulp_v = find(v);
    if(ulp_u == ulp_v)return;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet ds(n*n);
        queue<pair<int, int>>q;
       
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
            int node = n*i + j;
             for(int k = 0; k < 4; k++){
           int nrow = drow[k] + i;
           int ncol = dcol[k] + j;
           if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1){
             int adjNode = n*nrow + ncol;
             ds.unionbysize(node, adjNode);
           }
             }
            }
            else q.push({i, j});
        }
        }
        if(q.empty())return n*n;
        int ans = 0;
        while(!q.empty()){
        set<int>st;
           auto it = q.front();
           q.pop();
           int row = it.first;
           int col = it.second;
           for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1){
                int node = nrow*n + ncol;
               st.insert(ds.find(node));
            }
           }
           int count = 0;
           for(auto it: st){
              count += ds.size[it];
           }
           ans = max(ans, 1+count);
        }
       
        return ans;
    }
};
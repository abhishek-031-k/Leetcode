class DisJointSet{
public:
vector<int>parent, size;
DisJointSet(int n){
    size.resize(n+1, 1);
    parent.resize(n+1, 0);
    for(int i = 0; i <= n; i++)parent[i] = i;
}
 
 int find(int node){
    if(node == parent[node])return node;
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int>st(restricted.begin(), restricted.end());
        DisJointSet ds(n);
        for(auto &it: edges){
            if(st.count(it[0]) || st.count(it[1]))continue;
            ds.unionbysize(it[0], it[1]);
        }
      
        return ds.size[ds.find(0)];
    }
};
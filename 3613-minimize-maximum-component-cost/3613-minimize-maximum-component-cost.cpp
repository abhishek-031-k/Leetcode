class DisJointSet{
    public:
    vector<int>parent, size;
    DisJointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i= 0; i <= n; i++)parent[i] = i;
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
    int minCost(int n, vector<vector<int>>& edges, int k) {
    DisJointSet ds(n);
    int ans = 0;
    int component = n;
sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];}); 
       for(auto &it: edges){
        if(ds.find(it[0]) != ds.find(it[1])){
        ds.unionbysize(it[0], it[1]);
         component--;
        }
        if(component == k)return it[2];
    }
    return 0;
    }
};
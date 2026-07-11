class DisJointSet{
    public:
    vector<int>size, parent, edgecount;
    DisJointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1, 0);
        edgecount.resize(n+1, 0);
        for(int i = 0; i <= n; i++)parent[i] = i;
    }

    int find(int node){
        if(parent[node] == node)return node;
        return parent[node] = find(parent[node]);
    }

    void unionbysize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v){
            edgecount[ulp_u]++;
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            edgecount[ulp_v] += edgecount[ulp_u] + 1;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            edgecount[ulp_u] += edgecount[ulp_v] + 1;;
        }
    }

};


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         DisJointSet ds(n);
         for(auto &it: edges){
          ds.unionbysize(it[0], it[1]);
         }
         int ans = 0;
         for(int i = 0; i < n; i++){
          if(ds.find(i) == i){
            int node = ds.size[i];
            if(node*(node-1)/2 == ds.edgecount[i])ans++;
          }
         }
         return ans;
    }
};
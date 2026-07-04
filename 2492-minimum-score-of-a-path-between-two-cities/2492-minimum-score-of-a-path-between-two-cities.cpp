class DisJointSet{
    public:
    vector<int>parent, size;
    DisJointSet(int n){
     parent.resize(n+1, 0);
     size.resize(n+1, 0);
     for(int i = 0; i <= n; i++)parent[i] = i;
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
    int minScore(int n, vector<vector<int>>& roads) {
        DisJointSet ds(n);
        int mini = INT_MAX;
        for (auto& it : roads) {
          ds.unionbysize(it[0], it[1]);
        }
        
        for(auto& it: roads){
            if(ds.find(it[0]) == ds.find(1))mini = min(mini, it[2]);
        }
       return mini;
    }
};
class DisJointSet{
    public:
    vector<int>rank, parent, size;
    DisJointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
       parent.resize(n+1, 0);
       for(int i = 0; i <= n; i++)parent[i] = i;
    }

    int find(int node){
        if(parent[node] == node)return node;
        return parent[node] = find(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])parent[ulp_v] = ulp_u;
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      vector<bool>ans;
      DisJointSet ds(n);
      for(int i = 1; i < n; i++){
        if(nums[i] - nums[i-1] <= maxDiff){
            ds.unionbysize(i, i-1);
        }
      }
        for(auto &it : queries){
            if(ds.find(it[0]) == ds.find(it[1]))ans.push_back(true);
            else ans.push_back(false);
        }
      return ans;
    }
};
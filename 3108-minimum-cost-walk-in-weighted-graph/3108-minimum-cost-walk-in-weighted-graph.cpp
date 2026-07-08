
class DisJointSet {
public:
    vector<int> parent, size, rank;
   DisJointSet(int n){
    parent.resize(n+1, 0);
    size.resize(n+1, 1);
    rank.resize(n+1, 0);
    for(int i = 0; i <= n; i++)parent[i] = i;
    }
    int find(int node){
        if(node == parent[node])return node;
        return parent[node] = find(parent[node]);
    }

    void unionbysize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_v == ulp_u)return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void unionbyrank(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       DisJointSet ds(n);
       for(auto &it: edges){
       ds.unionbysize(it[0], it[1]);
       }
       vector<int>cost(n, -1);
       for(auto &it: edges){
         int root = ds.find(it[0]);
         cost[root] = cost[root] & it[2];
       }
       vector<int>ans;
       for(auto &it: query){
         if(ds.find(it[0]) != ds.find(it[1]))ans.push_back(-1);
         else if(it[0] == it[1])ans.push_back(0);
         else ans.push_back(cost[ds.find(it[0])]);
       }
       return ans;
    }
};
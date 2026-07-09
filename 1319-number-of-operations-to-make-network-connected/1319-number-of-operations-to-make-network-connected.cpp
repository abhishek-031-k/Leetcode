
  class DisjointSet{
  public:
   vector<int>rank,parent, size;
    DisjointSet(int n){
    rank.resize(n+1, 0);
    parent.resize(n+1, 0);
    size.resize(n+1, 0);
    for(int i = 0; i < n; i++)parent[i] = i;
    }

   int find(int node){
    if(node == parent[node])return node;
    return parent[node] = find(parent[node]);
   }

   void unionByRank(int u, int v){
    int ulp_u = find(u);
    int ulp_v = find(v);
    if(ulp_u == ulp_v)return;
    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
       parent[ulp_v] = ulp_u;
    }
    else {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
   }

    void unionBySize(int u, int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(n-1 > size)return -1;
        DisjointSet ds(n);
        for(auto &it: connections){
         ds.unionBySize(it[0], it[1]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i)count++;
        }
        return count-1;
    }
};
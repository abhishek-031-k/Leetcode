class DisjointSet{
    public:
    vector<int>rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i = 0; i <= n; i++)parent[i] = i;
    }

    int find(int node){
        if(node == parent[node])return node;
        return parent[node] = parent[find(parent[node])];
    }

   void unionbyrank(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v]){
         parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{ parent[ulp_v] = ulp_u;
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
    else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
   }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
     int maxrow = 0, maxcol = 0;
     for(auto it : stones){
        maxrow = max(maxrow, it[0]);
        maxcol = max(maxcol, it[1]);
     }
     DisjointSet ds(maxrow + maxcol + 1);
     unordered_map<int, int>uniqueNodes;
     for(auto &it: stones){
        int noderow = it[0];
        int nodecol = it[1] + maxrow + 1;
        ds.unionbysize(noderow, nodecol);
        uniqueNodes[noderow] = 1;
        uniqueNodes[nodecol] = 1;
     }
     int count = 0;
     for(auto &it : uniqueNodes){
        if(ds.find(it.first) == it.first)count++;
     }
     return n - count;
    }
};
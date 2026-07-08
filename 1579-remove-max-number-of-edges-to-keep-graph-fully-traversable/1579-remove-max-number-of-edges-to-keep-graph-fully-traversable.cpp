class DisJointSet {
public:
    vector<int> parent, size, rank;
    DisJointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for(int i = 0; i <= n; i++)parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])return node;
        return parent[node] = find(parent[node]);
    }

    void unionbysize(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
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
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisJointSet alice(n), bob(n);
        int ans = 0;
        for(auto &it : edges){
           if(it[0] == 3){
          bool flag = false;
        if(alice.find(it[1]) != alice.find(it[2])){
          alice.unionbysize(it[1], it[2]);
          flag = true;
    }
    if(bob.find(it[1]) != bob.find(it[2])){
        bob.unionbysize(it[1], it[2]);
        flag = true;
    }
    if(!flag) ans++;
       }
        }
          for(auto &it : edges){
             if(it[0] == 1){
              if(alice.find(it[1]) == alice.find(it[2]))ans++;
               else alice.unionbysize(it[1], it[2]);
            }
            else if(it[0] == 2){
                 if(bob.find(it[1]) == bob.find(it[2]))ans++;
               else bob.unionbysize(it[1], it[2]);
            }
        }
       if(alice.size[alice.find(1)] != n || bob.size[bob.find(1)] != n)return -1;
        return ans;
    }
};
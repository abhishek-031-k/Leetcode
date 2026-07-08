class DisJointSet{
    public:
    vector<int>parent, rank, size;
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
        if(parent[ulp_u] < parent[ulp_v])parent[ulp_u] = ulp_v;
        else if(parent[ulp_v] < parent[ulp_u])parent[ulp_v] = ulp_u;
        else {
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
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests){
        DisJointSet ds(n);
        vector<bool>ans;
        for (auto &it : requests) {
            int pu = ds.find(it[0]);
            int pv = ds.find(it[1]);
            bool flag = true;
            for (auto &x : restrictions) {
                int pa = ds.find(x[0]);
                int pb = ds.find(x[1]);
                if ((pu == pa && pv == pb) || (pu == pb && pv == pa)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ds.unionbysize(it[0], it[1]);
                ans.push_back(true);
            } 
            else ans.push_back(false);
            }
        
        return ans;
    }
};
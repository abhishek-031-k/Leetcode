class DisJointSet {
public:
    vector<int> parent, size, rank;
    DisJointSet(int n) {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet ds(n);
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end())mpp[mail] = i;
                else ds.unionbysize(i, mpp[mail]);
            }
        }
        vector<vector<string>> merge(n);
        for (auto& it : mpp) {
            string mail = it.first;
            int node = ds.find(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge[i].empty())continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& mail : merge[i])
                temp.push_back(mail);
            ans.push_back(temp);
        }
     return ans;
    }
};

class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)parent[i] = i;
    }
    int find(int node) {
        if (parent[node] == node)return node;
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
};

class Solution {
public:
vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        for (int i = 0; i < queries.size(); i++)queries[i].push_back(i);
        sort(queries.begin(), queries.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });
        DisJointSet ds(n);
        vector<bool> ans(queries.size());
        int j = 0, m = edgeList.size(), k = queries.size();
        for (int i = 0; i < k; i++) {
            while (j < m && edgeList[j][2] < queries[i][2]) {
                ds.unionbysize(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            if (ds.find(queries[i][0]) == ds.find(queries[i][1]))ans[queries[i][3]] = true;
            else ans[queries[i][3]] = false;
        }
        return ans;
    }
};
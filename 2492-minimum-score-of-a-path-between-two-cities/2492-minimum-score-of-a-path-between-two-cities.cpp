class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        queue<int> q;
        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        q.push(1);
        int mini = INT_MAX;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto& it : adj[node]) {
            mini = min(mini, it.second);
                if (!vis[it.first]) {
                    q.push(it.first);
                }
            }
        }
        return mini;
    }
};
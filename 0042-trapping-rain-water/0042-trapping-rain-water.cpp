class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, height[0]), suff(n, height[n - 1]);
        for (int i = 1; i < n; i++)pre[i] = max(height[i], pre[i - 1]);
        for (int i = n - 2; i >= 0; i--)suff[i] = max(height[i], suff[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(pre[i], suff[i]) - height[i];
        }
        return ans;
    }
};
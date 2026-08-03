class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int take = 0;
        int ans = INT_MIN;
        for (int i = ind; i < min(n, ind + 3); i++) {
            take += nums[i];
            ans = max(ans, take - solve(i + 1, nums, dp));
        }
        return dp[ind] = ans;
    }

    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int sum = solve(0, nums, dp);
        if (sum == 0) return "Tie";
        if (sum > 0) return "Alice";
        return "Bob";
    }
};
class Solution {
public:
    int solve(int n, vector<int>& nums) {
        vector<int> dp(n + 1, 0);
        int ans = INT_MIN;
        for (int ind = n - 1; ind >= 0; ind--) {
            int take = 0, ans = INT_MIN;
            for (int i = ind; i < min(n, ind + 3); i++) {
                take += nums[i];
                 ans = max(ans, take - dp[i + 1]);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }

    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        int sum = solve(n, nums);
        if (sum == 0)
            return "Tie";
        if (sum > 0)
            return "Alice";
        return "Bob";
    }
};
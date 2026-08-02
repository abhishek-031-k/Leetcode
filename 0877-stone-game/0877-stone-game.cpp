class Solution {
public:

      int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
       if(i == j)return nums[i];
       if(dp[i][j] != -1)return dp[i][j];
       return dp[i][j] = max(nums[i] - solve(i+1, j, nums, dp), nums[j] - solve(i, j-1, nums, dp));
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int sum = solve(0, n-1, piles, dp);
        return sum >= 0 ? true : false;
    }
};
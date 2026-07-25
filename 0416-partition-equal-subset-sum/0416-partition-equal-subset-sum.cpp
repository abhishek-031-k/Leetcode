class Solution {
public:

   bool solve(int ind, int sum, vector<int>&nums, vector<vector<int>>&dp){
    if(sum == 0)return true;
    if(ind == 0)return (sum == nums[ind]);
    if(dp[ind][sum] != -1)return dp[ind][sum];
    int nottake = solve(ind-1, sum, nums, dp);
    int take = false;
    if(sum >= nums[ind])take = solve(ind-1, sum-nums[ind], nums, dp);
    return dp[ind][sum] = take || nottake;
   }

    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target%2 != 0)return false;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target/2+1, -1));
        return solve(n-1, target/2, nums, dp);
    }
};
class Solution {
public:
 
    int solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == 0){
        if(nums[0] == 0 && target == 0)return 2;
        if(nums[0] == target || target == 0)return 1;
         return 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        int nottake = solve(ind-1, target, nums, dp);
        int take = 0;
        if(nums[ind] <= target)take =  solve(ind-1, target - nums[ind], nums, dp);
        return dp[ind][target] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int d) {
       int n = nums.size();
       int totalsum = accumulate(nums.begin(), nums.end(), 0);
   
       if((totalsum - d) < 0 || (totalsum - d) % 2)return false;
       int target = (totalsum - d)/2;
       vector<vector<int>>dp(n, vector<int>(target+1, -1));
       return solve(n-1, target, nums, dp);
    }
};
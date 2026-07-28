class Solution {
public:

    int solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
         if(ind == 0){
       if(target == 0)return 0;
       if(nums[0] == target)return 1;
           return -1e9;
             }
        if(target == 0)return 0;
        if(dp[ind][target] != -1)return dp[ind][target];
        int nottake = solve(ind-1, target, nums, dp);
        int take = -1e9;
        if(nums[ind] <= target)take = 1 + solve(ind-1, target - nums[ind], nums, dp);
        return dp[ind][target] = max(take, nottake);
    }
 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int ans = solve(n-1, target, nums, dp);
        if(ans < 0)return -1;
        else return ans;
    }
};
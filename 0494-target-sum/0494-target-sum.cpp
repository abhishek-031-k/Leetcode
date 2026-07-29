class Solution {
public:
 
    int solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
      int n = nums.size();
       
        for (int i = 0; i <= target; i++) {
            if (i == 0 && nums[0] == 0)dp[0][0] = 2;
            else if (i == 0 || nums[0] == i)dp[0][i] = 1;
        }

        for(int ind = 1; ind < n; ind++){
        for(int t = 0; t <= target; t++){
            int nottake = dp[ind-1][t];
            int take = 0;
            if(nums[ind] <= t)take = dp[ind-1][t-nums[ind]];
            dp[ind][t] = take + nottake;
        }
        }
       return dp[n-1][target];
    }

    int findTargetSumWays(vector<int>& nums, int d) {
       int n = nums.size();
       int totalsum = accumulate(nums.begin(), nums.end(), 0);
   
       if((totalsum - d) < 0 || (totalsum - d) % 2)return false;
       int target = (totalsum - d)/2;
       vector<vector<int>>dp(n, vector<int>(target+1, 0));
       return solve(n-1, target, nums, dp);
    }
};
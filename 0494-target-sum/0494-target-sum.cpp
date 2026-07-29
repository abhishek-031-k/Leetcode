class Solution {
public:
 
    int solve(int ind, int target, vector<int>&nums){
      int n = nums.size();
        vector<int>prev(target+1, 0), curr(target+1, 0);
        for (int i = 0; i <= target; i++) {
            if (i == 0 && nums[0] == 0)prev[0] = 2;
            else if (i == 0 || nums[0] == i)prev[i] = 1;
        }

        for(int ind = 1; ind < n; ind++){
        for(int t = 0; t <= target; t++){
            int nottake = prev[t];
            int take = 0;
            if(nums[ind] <= t)take = prev[t-nums[ind]];
            curr[t] = take + nottake;
        }
        prev = curr;
        }
       return prev[target];
    }

    int findTargetSumWays(vector<int>& nums, int d) {
       int n = nums.size();
       int totalsum = accumulate(nums.begin(), nums.end(), 0);
   
       if((totalsum - d) < 0 || (totalsum - d) % 2)return false;
       int target = (totalsum - d)/2;
      
       return solve(n-1, target, nums);
    }
};
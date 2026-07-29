class Solution {
public:

    int solve(int amount, vector<int>&coins){
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(amount+1, 0));
        for(unsigned long long i = 0; i <= amount; i++)dp[0][i] = (i % coins[0] == 0);

      for(unsigned long long ind = 1; ind < n; ind++){
      for(unsigned long long t = 0; t <= amount; t++){
         unsigned long long nottake = dp[ind-1][t];
         unsigned long long take = 0;
          if(coins[ind] <= t)take = dp[ind][t - coins[ind]];
            dp[ind][t] = take + nottake;
      }
      }
      return int(dp[n-1][amount]);
    }

    int change(int amount, vector<int>& coins) {
        return solve(amount, coins);
    }
};
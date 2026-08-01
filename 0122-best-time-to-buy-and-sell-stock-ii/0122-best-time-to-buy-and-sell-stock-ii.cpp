class Solution {
public:

    int solve(int n, vector<int>&prices, vector<vector<int>>&dp){
       dp[n][0] = dp[n][1] = 0;

       for(int ind = n-1; ind >= 0; ind--){
       for(int buy = 0; buy < 2; buy++){
         if(buy){
            dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
        }
        else {
              dp[ind][buy] = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
        }
       }
       }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(n, prices, dp);
    }
};
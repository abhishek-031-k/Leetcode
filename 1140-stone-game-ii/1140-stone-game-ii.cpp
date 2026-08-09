class Solution {
public:
    int solve(int i, int m, vector<int>& piles, vector<int>& suff, vector<vector<int>>& dp) {
        int n = piles.size();
        if(i >= n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int ans = 0;
         for(int x = 1; x <= 2*m && i+x <= n; x++) {
            int next = solve(i+x, max(m, x), piles, suff, dp);
            ans = max(ans, suff[i] - next);
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suff(n+1, 0);
        for(int i = n-1; i >= 0; i--)suff[i] = suff[i+1] + piles[i];
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, 1, piles, suff, dp);
    }
};
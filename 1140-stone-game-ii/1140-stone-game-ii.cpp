class Solution {
public:

//    int solve(int i, int m, int n, vector<int>&piles){
         
//    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> arr(1);
        for(int i = 0; i<n; i++) arr.push_back(piles[i]);
        vector<int> prefSum(n+1);

        prefSum[0] = 0;
        for(int i = 1; i<=n; i++) prefSum[i] = prefSum[i-1] + arr[i];
        int dp[n+5][n+5];
        memset(dp, -1, sizeof(dp));
        auto findAns = [&](auto &self, int l, int r) -> int{
            if(l>=n+1) return 0;
            if(dp[l][r]+1) return dp[l][r];
            int range = r - l + 1;
            int ttl = 0;
            int nextSum;
            int ans = -1000000000;
            int cnt = 0;
            for(int i = l; i<n+1&&i<=r; i++){
                cnt++;
                ttl += arr[i];
                nextSum = prefSum[n] - prefSum[i];
                ans = max(ans, ttl + nextSum - self(self, i+1, min(i+max(range, 2*cnt), n)));
            }
            return dp[l][r] = ans;
        };

        return findAns(findAns, 1, 2);
    }
};
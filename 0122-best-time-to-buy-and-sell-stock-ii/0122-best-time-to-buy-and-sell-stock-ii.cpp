class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<int>ahead(2, 0), curr(2, 0);
       for(int ind = n-1; ind >= 0; ind--){
       for(int buy = 0; buy < 2; buy++){
         if(buy)curr[buy] = max(-prices[ind] + ahead[0], ahead[1]);
         else curr[buy] = max(prices[ind] + ahead[1], ahead[0]);
        }
       ahead = curr;
       }
        return ahead[1];
    }
};
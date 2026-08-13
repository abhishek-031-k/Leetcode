class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

       double  ans = 0;
        int j = discounts.size() - 1, n = prices.size();
        for(int i = n-1; i >= 0; i--){
            if(j >= 0){
                ans += (prices[i] * (100.0 - discounts[j]))/100.0;
                j--;
            }
            else ans += prices[i];
        }
        return ans;
    }
};
class Solution {
public:

     long long int time(int mid, vector<int>&piles){
      long long  int totaltime = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % mid == 0)totaltime += piles[i]/mid;
            else if(piles[i] < mid)totaltime += 1;
            else totaltime += piles[i]/mid + 1;
        }
        return totaltime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 0;
        for(int i = 0; i < n; i++)high = max(high, piles[i]);
        int ans = INT_MAX;
        while(high >= low){
            int mid = low + (high - low)/2;
            if(time(mid, piles) <= h){
                ans = min(ans, mid);
               high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};